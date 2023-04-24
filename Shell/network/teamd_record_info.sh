#!/bin/bash

#Instruction:新teamd拉起前，在老容器中调用，保存team已协商上网口的lacpdu对端信息
#调用时越贴近新teamd拉起越好，以避免保存到的对端信息在新teamd拉起前发生变动
#LACPDU_INFO_FILE_PATH定义的路径需要是新老容器共享的路径
#入参可以是team聚合口名称，也可以不传，不传时会自动保存所有teamd正常运行的lacp模式的team口

LACP_UPG_INFO_FILE_PATH='/tmp/team'
LOG_FILE=/var/upg_record_lacp_partner_info.log

function log_error()
{
    local msg=$*
    echo "`date` [error] $msg" >> "${LOG_FILE}"
}

function log_warn()
{
    local msg=$*
    echo "`date` [warn] $msg" >> "${LOG_FILE}"
}

function log_info()
{
    local msg=$*
    echo "`date` [info] $msg" >> "${LOG_FILE}"
}

function get_all_team_devs()
{
    local net_dev_root='/sys/class/net'
    local net_devs=$(ls ${net_dev_root})
    net_devs=(${net_devs// /})
    local team_devs=()
    local ret

    for net_dev in "${net_devs[@]}"; do
        ret=$(ethtool -i "${net_dev}" 2>/dev/null | grep driver | grep "\<team\>")
        [[ -n "${ret}" ]] && team_devs+=("${net_dev}")
    done

    echo "${team_devs[@]}"
}

function record_one()
{
    local ret
    local team_dev=$1
    local team_dev_lacpdu_info_file="${LACP_UPG_INFO_FILE_PATH}/${team_dev}"
    local team_dev_lacpdu_info_tmp_file="${LACP_UPG_INFO_FILE_PATH}/tmp_${team_dev}"

    # teamd不存在，异常情况，抛错
    ret=$(teamd -t "${team_dev}" -e 2>&1)
    if [[ $? -ne 0 ]]; then
        log_error "device ${team_dev} teamd is not exist, err:${ret}"
        return 1
    fi

    # 获取team设备的所有信息
    local team_dev_state=$(teamdctl ${team_dev} state dump 2>/dev/null)
    log_info "${team_dev} device info:${team_dev_state}"

    # 非lacp模式的team设备直接直接返回
    local team_runner=$(echo ${team_dev_state} | jq -r ".setup.runner_name | @text")
    if [[ "${team_runner}" != "lacp" ]]; then
        log_info "${team_dev} runner ${team_runner} is not lacp, ignore"
        return 0
    fi

    ret=$(jq -n "{selected_ports:{}}"> "${team_dev_lacpdu_info_tmp_file}" 2>&1)
    if [[ $? -ne 0 ]]; then
        log_error "$${team_dev_lacpdu_info_tmp_file} create failed, err:${ret}"
        return 1
    fi

    local team_members=$(echo ${team_dev_state} | jq -r ".ports | keys[] | @text")
    team_members=(${team_members// /})
    local selected_members=()
    for team_member in "${team_members[@]}"; do
        local selected=$(echo ${team_dev_state} | jq -r ".ports.${team_member}.runner.selected | @text")
        if [[ "${selected}" != "true" ]]; then
            log_info "${team_dev} member ${team_member} is not selected, ignore"
            continue
        fi

        local selected_member_lacpdu_info=$(echo "${team_dev_state}" | jq ".ports.${team_member}.runner.partner_lacpdu_info")
        ret=$(jq ".selected_ports += {${team_member}:${selected_member_lacpdu_info}}" "${team_dev_lacpdu_info_tmp_file}" > "${team_dev_lacpdu_info_file}" 2>&1)
        if [[ $? -ne 0 ]]; then
            log_error "${team_dev} member ${team_member} record partner lacpdu info failed, err:${ret}"
            return 1
        fi

        ret=$(\cp -f "${team_dev_lacpdu_info_file}" "${team_dev_lacpdu_info_tmp_file}" 2>&1)
        if [[ $? -ne 0 ]]; then
            log_error "cp ${team_dev_lacpdu_info_file} to ${team_dev_lacpdu_info_tmp_file} failed, err:${ret}"
            return 1
        fi
    done

    ret=$(rm -f "${team_dev_lacpdu_info_tmp_file}" 2>&1)
    if [[ $? -ne 0  ]]; then
        log_error "delete ${team_dev_lacpdu_info_tmp_file} failed, err:${ret}"
        return 1
    fi

    return 0
}

function record_all()
{
    local team_devs=($(get_all_team_devs))

    for team_dev in "${team_devs[@]}"; do
        # 记录此team已协商上网口的对端信息
        record_one "${team_dev}"
        [[ $? -ne 0 ]] && return 1
    done

    return 0
}

function main()
{
    local ret
    local team_dev=$1

    ret=$(mkdir -p "${LACP_UPG_INFO_FILE_PATH}" 2>&1)
    if [[ $? -ne 0 ]]; then
        log_error "create ${LACP_UPG_INFO_FILE_PATH} failed, err:${ret}"
        return 1
    fi

    if [[ -z "${team_dev}" ]]; then
        record_all
    else
        record_one "${team_dev}"
    fi

    if [[ $? -ne 0 ]]; then
        log_error "upg record lacp partner info failed"
        return 1
    fi

    return 0
}

main $1
