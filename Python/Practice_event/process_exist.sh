#!/bin/bash

#File Name: process_exist.sh
#Author:lizhong
#Mail:423810942@qq.com
#Created Time: Fri 07 Feb 2020 09:34:43 PM PST
#Instruction:

function process_exist()
{
    res=`ps -ef | grep -v 'grep' | grep -o '\<event-report1\>'`
    
    if [ -n "$res" ]
    then
        return 0
    else
        return 1
    fi
}

process_exist
