#!/usr/bin/env python
# -*- coding:utf-8 -*-

#还是单独用supervisor监控inotify进程的好（更加方便进程的管理）
#避免孤儿进程和僵尸进程（可以采用捕获SIGCHLD信号，异步回收的方式）的产生
#但孤儿进程不便于管理，遂优先考虑使用supervisor单独管理监控进程

from multiprocessing import Process
from inotify import inotify, FileEvent

def main():
    f = FileEvent()
    print(f.get_path())

if __name__ == '__main__':
    main()