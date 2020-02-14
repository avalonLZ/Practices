#! /usr/bin/env python
# -*- coding: utf-8 -*-

from sys import exit

def main(arg):
    if arg is False:
        exit(1)
    elif arg is True:
        exit(0)
    else:
        #默认返回是0,执行成功
        return

if __name__ == '__main__':
    main(3)
