#!/usr/bin/env python
# -*- coding:utf-8 -*-

#还是单独用supervisor监控inotify进程的好（更加方便进程的管理）
#避免孤儿进程和僵尸进程（可以采用捕获SIGCHLD信号，异步回收的方式防止僵尸进程）的产生
#但孤儿进程不便于管理，遂优先考虑使用supervisor单独管理监控进程

from multiprocessing import Process
from inotify import inotify
from os import waitpid, WNOHANG, getpid#, system, popen
from signal import signal, SIGCHLD
from time import sleep

def wait_child_dead(*args):
    print('wait child dead...%s' % (args, ))
    pid, status = waitpid(-1, WNOHANG)
    print(pid,status)
    #res = system("ps -ef | grep -v 'grep' | grep -o '\<event-report\>'")
    #res = popen("ps -ef | grep -v 'grep' | grep -o '\<event-report\>'")
    #print res

def main():
    print ('Main pid:%d' % getpid())
    #注册信号处理函数，异步回收子进程资源
    signal(SIGCHLD, wait_child_dead)

    p = Process(target=inotify)
    #子进程启动后，会收到子进程pid+1的进程发来的SIGCHLD信号
    #应该是python内部调用的
    # 子进程start后才可获取其pid
    p.start()

    while True:
        print('Main Process pid:%d running...' % getpid())
        sleep(30)

if __name__ == '__main__':
    main()