#! /usr/bin/env python
# -*- coding: utf-8 -*-

from sys import exit

def main(arg):
        #shell中程序返回1
    if arg is False:
        exit(1)
        #shell中程序返回0
    elif arg is True:
        exit(0)
    else:
        #shell中程序返回0
        return 3

if __name__ == '__main__':
    main(3)
