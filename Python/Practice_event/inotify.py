#!/usr/bin/env python
# -*- coding:utf-8 -*-

from os.path import exists
from pyinotify import ProcessEvent, EventsCodes, WatchManager, \
    Notifier
from time import sleep
from threading import Thread
from setproctitle import setproctitle
from os import getpid

class MyDirEventThread():
    def dir_create_thread(self):
        print('dir file create event deal thread start...')
        sleep(30)
        print('dir file create event deal thread end...')

class MyFileEventHandler(ProcessEvent):
    def process_IN_MODIFY(self, event):
        print('file MODIFY')

#单线程执行，但阻塞住了后，来了事件，依然会存放于队列中
#队列中的事件按顺序依次执行
class MyDirEventHandler(ProcessEvent):
    # 1、创建线程
    # 2、删除文件
    # 3、执行线程
    # 4、线程内尝试获取文件锁
    # 5、获取锁成功，则继续执行
    # 6、获取锁超时，则返回失败此事件未执行
    def process_IN_CREATE(self, event):
        print('dir file Create, event start...')
        t_event = MyDirEventThread()
        t = Thread(target=t_event.dir_create_thread, name='CreateDeal')
        print('delete dir file')
        t.start()
        print('dir file Create, event end...')


    def process_IN_DELETE(self, event):
        # print('sleep 30s start...')
        # sleep(30)
        # print('sleep end')
        print('dir file Delete')

    #路径下的文件内容被修改，才会触发此事件
    def process_IN_MODIFY(self, event):
        print('dir MODIFY')

class FileEvent(object):
    def __file_init(self):
        path = '/home/lz/Desktop/test_inotify/alarm'
        return path

    def __init__(self):
        self.__muti_event = 0
        self.__event_handler = None
        self.__path = ''

        self.__path = self.__file_init()
        self.__muti_event = EventsCodes.FLAG_COLLECTIONS['OP_FLAGS']['IN_MODIFY']
        self.__event_handler = MyFileEventHandler()

    def get_path(self):
        return self.__path

    def get_muti_event(self):
        return self.__muti_event

    def get_event_handler(self):
        return self.__event_handler

class DirEvent(object):
    def __dir_init(self):
        path = '/home/lz/Desktop/test_inotify/'
        return path

    def __init__(self):
        self.__muti_event = 0
        self.__event_handler = None
        self.__path = ''

        self.__path = self.__dir_init()
        self.__muti_event = EventsCodes.FLAG_COLLECTIONS['OP_FLAGS']['IN_CREATE']\
                        | EventsCodes.FLAG_COLLECTIONS['OP_FLAGS']['IN_DELETE']\
                            | EventsCodes.FLAG_COLLECTIONS['OP_FLAGS']['IN_MODIFY']
        self.__event_handler = MyDirEventHandler()

    def get_path(self):
        return self.__path

    def get_muti_event(self):
        return self.__muti_event

    def get_event_handler(self):
        return self.__event_handler


def inotify():
    setproctitle('event-report')
    print('EventReport %d Process start...' % getpid())

    file_event = FileEvent()
    dir_event = DirEvent()

    #需要保证，监听前，该路径已存在
    #dir_path = '/home/lz/Desktop/test_inotify/'
    #需要保证，监听前，该文件已存在
    #file_path = '/home/lz/Desktop/test_inotify/alarm'
    #dir_muti_event = EventsCodes.FLAG_COLLECTIONS['OP_FLAGS']['IN_CREATE']\
    #             | EventsCodes.FLAG_COLLECTIONS['OP_FLAGS']['IN_DELETE']\
    #                 | EventsCodes.FLAG_COLLECTIONS['OP_FLAGS']['IN_MODIFY']

    #file_muti_event = EventsCodes.FLAG_COLLECTIONS['OP_FLAGS']['IN_MODIFY']

    #file_handler = MyFileEventHandler()
    #dir_handler = MyDirEventHandler()

    wm = WatchManager()
    wm.add_watch(dir_event.get_path(), dir_event.get_muti_event(),
                 dir_event.get_event_handler())
    #可以这样使用，同时监听，不同路径/文件的不同操作
    wm.add_watch(file_event.get_path(), file_event.get_muti_event(),
                 file_event.get_event_handler())

    notifier = Notifier(wm)
    print('inotify loop...')
    notifier.loop()

if __name__ == '__main__':
    inotify()

