#! /usr/bin/env python
# -*- coding: utf-8 -*-

from import_children_1 import children

#引用多模块中的同名类或方法,最后引用的会覆盖之前引用的方法
from import_children_2 import children

def main():
    c = children()

    try:
        print(c.get_x())
    except:
        print('c no children_1')

    try:
        print(c.get_y())
    except:
        print('c no children_2')

if __name__ == '__main__':
    main()