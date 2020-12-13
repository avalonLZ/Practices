#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main():
    t_list = ['li','ren']

    # list转字符串，可以用以下写法
    tt_list = ','.join(t_list)
    print(tt_list, type(tt_list), t_list, type(t_list))

if __name__ == '__main__':
    main()