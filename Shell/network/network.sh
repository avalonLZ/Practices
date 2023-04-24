#!/bin/bash

#File Name: network.sh
#Author:lizhong
#Mail:423810942@qq.com
#Created Time: Sun 13 Dec 2020 03:27:05 AM PST
#Instruction:记录网络相关常用shell命令（也可能是一个小函数）

# 网络设备内核根路径
NET_DEV_ROOT='/sys/class/net'

# PCI设备地址根路径
PCI_DEV_ROOT='/sys/bus/pci/devices'

# PCI驱动设备地址根路径
PCI_DRV_ROOT='/sys/bus/pci/drivers'

# 通用日志函数
function log_error()
{
	local msg=$*
	local LOG_FILE=$1

	[ "${LOG_FILE}" == '' ] && LOG_FILE='/dev/stdout'

	echo "`date` [error] $msg" >> "${LOG_FILE}"
}

# 获取本机所有物理网口名称
function get_ifaces_name()
{
    local ifaces_name=$(/bin/ls "${NET_DEV_ROOT}" | grep -E "^eth[0-9]+$|^ens[0-9]+$")
    echo -e "${ifaces_name}\n"
}
get_ifaces_name

# 获取网口PCI地址、驱动名称、设备ID、厂商ID、子设备ID、子厂商ID
function get_iface_info()
{
    local iface_name=$1
    if [ "${iface_name}" == '' ]; then
        local ifaces_name=$(get_ifaces_name)
        iface_name=$(echo ${ifaces_name} | awk '{print $1}')
    fi

    # pci地址
    local pci_addr=$(basename $(readlink "${NET_DEV_ROOT}/${iface_name}/device"))

    # 驱动名称
    local drv_name=$(basename $(readlink "${NET_DEV_ROOT}/${iface_name}/device/driver"))

    # 设备ID
    local dev_id=$(cat "${NET_DEV_ROOT}/${iface_name}/device/device")

    # 厂商ID
    local vendor_id=$(cat "${NET_DEV_ROOT}/${iface_name}/device/vendor")

    # 子设备ID
    local sub_dev_id=$(cat "${NET_DEV_ROOT}/${iface_name}/device/subsystem_device")

    # 子厂商ID
    local sub_vendor_id=$(cat "${NET_DEV_ROOT}/${iface_name}/device/subsystem_vendor")

    echo -e "iface:${iface_name}\npci_addr:${pci_addr}\ndrv_name:${drv_name}\ndev_id:${dev_id}\nvendor_id:${vendor_id}\nsub_dev_id:${sub_dev_id}\nsub_vendor_id:${sub_vendor_id}\n"
}
get_iface_info
