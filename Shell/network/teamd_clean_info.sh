#!/bin/bash

#Instruction:清除upg_record_lacp_partner_info.sh产生的文件
#入参可以是team聚合口名称，也可以不传，不传时直接清空LACPDU_INFO_FILE_PATH下所有文件

LACP_UPG_INFO_FILE_PATH='/tmp/team'
LOG_FILE=/var/upg_clean_lacp_partner_info.log

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

function clean_one()
{
    local team_dev=$1
    local ret

    log_info "delete ${LACP_UPG_INFO_FILE_PATH}"/"${team_dev}"

    ret=$(rm -rf "${LACP_UPG_INFO_FILE_PATH}"/"${team_dev}" 2>&1)
    if [[ $? -ne 0 ]]; then
        log_error "delete ${LACP_UPG_INFO_FILE_PATH}/${team_dev} failed, err:${ret}"
        return 1
    fi

    return 0
}

function clean_all()
{
    local ret

    log_info "delete ${LACP_UPG_INFO_FILE_PATH}/*"

    ret=$(rm -rf "${LACP_UPG_INFO_FILE_PATH}"/* 2>&1)
    if [[ $? -ne 0 ]]; then
        log_error "delete ${LACP_UPG_INFO_FILE_PATH}/* failed, err:${ret}"
        return 1
    fi

    return 0
}

function main()
{
    local team_dev=$1

    if [[ -z "${team_dev}" ]]; then
        clean_all
    else
        clean_one "${team_dev}"
    fi

    if [[ $? -ne 0 ]]; then
        log_error "upg clean lacp partner info failed"
        return 1
    fi

    return 0
}

main $1

