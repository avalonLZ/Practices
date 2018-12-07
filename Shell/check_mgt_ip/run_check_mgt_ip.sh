#!/bin/bash

#File Name: run_check_mgt_ip.sh
#Author:lizhong
#Mail:423810942@qq.com
#Created Time: Thu 06 Dec 2018 07:58:08 PM PST
#Instruction:使用格式：./run_check_mgt_ip.sh [管理口] [期望ip] [期望网关]

./check_mgt_ip.sh $1 $2 $3 >> /var/log/check_mgt_ip.txt &
