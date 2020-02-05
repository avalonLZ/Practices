#!/usr/bin/env python
# -*- coding:utf-8 -*-

import ctypes

def m_add(x, y):
    return x + y

c_lib_so = '/home/lz/Desktop/Temp_Test/c/libso/libmyadd.so'
mylib = ctypes.cdll.LoadLibrary(c_lib_so)
mylib_handle = mylib.m_add(22, 33)
print('%d' % mylib_handle)

