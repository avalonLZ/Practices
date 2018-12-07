#!/bin/bash

#File Name: check_mgt_ip.sh
#Author:lizhong
#Mail:423810942@qq.com
#Created Time: Thu 06 Dec 2018 05:12:07 PM PST
#Instruction:每3分钟检查一次管理口ip（不存在期望ip,则添加期望ip），状态（不是UP状态则UP网口）以及静态路由（不存在网关时，添加期望网关地址）。使用格式：./check_mgt_ip.sh [管理口] [期望ip] [期望网关]

function get_date()
{
    date_info=$(date '+%Y-%m-%d %H:%M:%S')
    echo ${date_info}
}

function check_default_route()
{
    check_default_route_result=$(route | grep default | awk '{print $1}')

    if [ -z ${check_default_route_result} ]
    then
        #不存在默认路由
        echo "no have default route"
        echo `route add default gw $1` > /dev/null 2>&1
    else
        #存在默认路由
        echo "have_default_route"
    fi
}

function check_mgt_status()
{ 
    mgt_ip_info=$(ip a | grep $1)
    check_status_result=$(echo "${mgt_ip_info}" | grep "UP" | awk '{print $1}')
    
    if [ -z ${check_status_result} ]
    then
        #管理口DOWN状态
        echo "mgt status is DOWN"
        echo `ifconfig $1 up` > /dev/null 2>&1
    else
        #管理口UP状态
        echo "mgt status is UP"
    fi
    #echo ${check_status_result}
}

#检查管理口是否绑定了期望的ip地址
function check_mgt_ip()
{
    mgt_expect_ip=$2
    mgt_ip_info=$(ip a | grep $1)
    mgt_inet_info=$(echo "${mgt_ip_info}" | grep "inet")
    check_ip_result=$(echo "${mgt_inet_info}" |  grep "${mgt_expect_ip}" | awk '{print $1}')
    
    if [ -z ${check_ip_result} ]
    then
        #不存在期望ip
        echo "no have expect ip ${mgt_expect_ip}"
        echo `ip addr add $2 dev $1` > /dev/null 2>&1
    else
        #存在期望ip
        echo "have expect ip ${mgt_expect_ip}"
    fi
    #echo ${check_ip_result}
}

function run()
{
    get_date
    check_mgt_ip $1 $2
    check_mgt_status $1
    check_default_route $3
    echo -e ""
}

################main###############

while true
do
    run $1 $2 $3
    sleep 180
done
