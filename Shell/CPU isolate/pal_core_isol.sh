#!/bin/bash

#File Name: pal_core_isol.sh
#Instruction:该脚本用于将PAL_CFG中配置的CPU进行隔离
#注意：
#1.不支持幂等，需要多次执行时，请在非首次执行前，先自行恢复grub.cfg.bak为grub.cfg
#2.PAL_CFG文件格式请先用dos2unix和expend命令，转换windows换行符并消除掉tab

LOG_FILE='/var/log/pal_core_isol.log'
PAL_CFG='/etc/sinc-bgw/pal.conf'
GRUB_PATH='/boot/grub'
PAL_OTHER_NODE_CPU_ITEMS=(
    'control_cpu'
    'control_cpu_slave'
    'arp_cpu'
    'vnic_cpu'
    'sync_cpu'
    'kni_cpu'
)

# error日志接口
log_error()
{
    local msg=$*
    echo "`date` [error] $msg" >> "${LOG_FILE}"
}

# info日志接口
log_linfo()
{
    local msg=$*
    echo "`date` [linfo] $msg" >> "${LOG_FILE}"
}

# 获取指定node上，第index个cpu num
function get_cpu_num()
{
    local node_index=$1
    local cpu_index=$2
    local cpus_num=$(ls /sys/devices/system/node/node${node_index}/ | grep "^cpu[0-9]\+$" \
                    | grep -o "[0-9]\+" | sort -n)

    cpus_num=(${cpus_num// / })
    echo ","${cpus_num[${cpu_index}]}

    return 0
}

# 获取control_cpu、kni_cpu...等其他items的cpu num
function get_other_cpus_num()
{
    local node_index=0
    local cpu_index=0
    local cpus_num=""
    local tmp_num=""

    for item in ${PAL_OTHER_NODE_CPU_ITEMS[@]}; do
        node_index=$(cat ${PAL_CFG} | grep "\<${item}\>" | awk '{print $2}')
        cpu_index=$(cat ${PAL_CFG} | grep "\<${item}\>" | awk '{print $3}')
        tmp_num=$(get_cpu_num ${node_index} ${cpu_index})
        log_linfo "node:node${node_index}, ${item}_index:${cpu_index}, ${item}_num:${tmp_num}"
        cpus_num+=${tmp_num}
    done

    echo ${cpus_num}

    return 0
}

# 获取receiver_cpus和worker_cpus item的cpu num
function get_rev_work_cpus_num()
{
    local cpus_num=""
    local tmp_num=""

    #获取node列表
    local nodes=$(cat ${PAL_CFG} | grep -o "\<node[0-9]\+\>")
    nodes=(${nodes// / })
    for node in ${nodes[@]}; do
        local node_index=$(echo ${node} | grep -o "[0-9]\+")

        # 获取receiver_cpus的cpus num
        local receiver_cpus_index=$(cat ${PAL_CFG} | grep -A 3 "\<${node}\>" \
                                    | grep "receiver_cpus" | tr -s ' ' \
                                    | cut -d ' ' -f 3-)
        receiver_cpus_index=(${receiver_cpus_index// / })
        for cpu_index in ${receiver_cpus_index[@]}; do
            tmp_num=$(get_cpu_num ${node_index} ${cpu_index})
            log_linfo "node:node${node_index}, receiver_cpu_index:${cpu_index}, receiver_cpu_num:${tmp_num}"
            cpus_num+=${tmp_num}
        done

        # 获取worker_cpus的cpus num
        local worker_cpus_index=$(cat ${PAL_CFG} | grep -A 3 "\<${node}\>" \
                                    | grep "worker_cpus" | tr -s ' ' \
                                    | cut -d ' ' -f 3-)
        worker_cpus_index=(${worker_cpus_index// / })
        for cpu_index in ${worker_cpus_index[@]}; do
            tmp_num=$(get_cpu_num ${node_index} ${cpu_index})
            log_linfo "node:node${node_index}, worker_cpu_index:${cpu_index}, worker_cpu_num:${tmp_num}"
            cpus_num+=${tmp_num}
        done

    done

    echo ${cpus_num}
    return 0
}

# 检查PAL_CFG配置文件是否存在
function check_pal_cfg()
{
    if [[ ! -f "${PAL_CFG}" ]]; then
        log_error "${PAL_CFG} is not existed"
        return 1
    fi

    return 0
}

# 检查grub配置文件是否存在
function check_grub()
{
    if [[ ! -f "${GRUB_PATH}/grub.cfg" ]]; then
        log_error "${GRUB_PATH}/grub.cfg is not existed"
        return 1
    fi

    return 0
}

# 备份grub配置文件
function backup_grub()
{
    if [[ -f "${GRUB_PATH}/grub.cfg.bak" ]]; then
        log_linfo "${GRUB_PATH}/grub.cfg.bak is existed, no backup"
        return 0
    fi

    cp "${GRUB_PATH}/grub.cfg" "${GRUB_PATH}/grub.cfg.bak"
    if [[ $? -ne 0 ]]; then
        log_error "backup ${GRUB_PATH}/grub.cfg failed"
        return 1
    fi

    log_linfo "backup ${GRUB_PATH}/grub.cfg success"
    return 0
}

# 更新grub配置文件
function update_grub()
{
    local isolcpus=$1
    local kernel=$(uname -r)
    local line_num=$(cat ${GRUB_PATH}/grub.cfg | grep -n "/boot/vmlinuz-${kernel}" \
                    | grep -v "recovery" | awk -F ':' '{print $1}')

    sed -i "${line_num}s/$/ isolcpus=${isolcpus}/" "${GRUB_PATH}/grub.cfg"
    if [[ $? -ne 0 ]]; then
        log_error "update ${GRUB_PATH}/grub.cfg failed"
        return 1
    fi

    log_linfo "update ${GRUB_PATH}/grub.cfg success"
    return 0
}

function main()
{
    check_pal_cfg
    [[ $? -ne 0 ]] && return 1

    local isolcpus=""
    isolcpus+=$(get_other_cpus_num)
    isolcpus+=$(get_rev_work_cpus_num)
    isolcpus=${isolcpus#,}
    log_linfo "isolcpus=${isolcpus}"

    check_grub
    [[ $? -ne 0 ]] && return 1

    backup_grub
    [[ $? -ne 0 ]] && return 1

    update_grub ${isolcpus}
    [[ $? -ne 0 ]] && return 1

    return 0
}

main
if [[ $? -ne 0 ]]; then
    echo "exec failed! the detailed log please see ${LOG_FILE}"
    exit 1
fi

echo "exec success, the detailed log please see ${LOG_FILE}"
exit 0
