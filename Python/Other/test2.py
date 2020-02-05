#!/usr/bin/env python
# -*- coding:utf-8 -*-

import ctypes
'''
class lz_child():
    def __init__(self):
        self.__x = 1
        self.__y = 2

    def my_return(self):
        return self.__x + self.__y

class lz():
    def __init__(self):
        self.__x = 10.12
        self.__y = 20.34

        self.child = lz_child()

    def my_print(self):
        print('x=%f, y=%f add=%f' % (self.__x, self.__y,
                                     self.__my_add()))

    def __my_add(self):
        print('x:%f,y:%f,child:%f' % (self.__x, self.__y,
                                     self.child.my_return()))
        return self.__x + self.__y + self.child.my_return()

def test_lz():
    l=lz()
    l.my_print()

test_lz()

'''

'''
dict_test = {'eth0':{'speed':'100', 'model':'dpdk'},
             'eth1':{'speed':'1000', 'model':'kernel'}}

for i,v in dict_test.iteritems():
    print('key:%s, value:%s' % (i, v))

    for j,k in v.iteritems():
        if j == 'speed':
            print("v.vaule:%s" % k)

'''

class dict_test():
    def __init__(self):
        self.__my_dict = {}

    def create(self, **kwargs):
        if bool(kwargs):
            print('kw.key:%s' % kwargs.keys())
        else:
            print('kw is empty')

def dict_t():
    d=dict_test()
    d.create(f=123, x=456)

dict_t()


list1=[]
if bool(list1):
    print('list1 not is empty')
else:
    print('list1 is empty')