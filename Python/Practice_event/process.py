#!/usr/bin/env python
# -*- coding:utf-8 -*-

from multiprocessing import Process
from inotify import inotify, FileEvent

def main():
    f = FileEvent()
    print(f.get_path())

if __name__ == '__main__':
    main()