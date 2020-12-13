#!/usr/bin/env python
# -*- coding:utf-8 -*-

def main():
    dirt1 = {}
    k = 'k1'
    if k in dirt1.keys():
        print(dirt1[k])
    else:
        print('k key is not exist!')

if __name__ == '__main__':
    main()