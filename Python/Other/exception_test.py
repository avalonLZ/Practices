#!/usr/bin/env python
# -*- coding:utf-8 -*-

class MyException(Exception):

    def __str__(self):
        return "异常"

def exception_test():
#    print("123")
    raise MyException
#    print("456")


def test():
    try:
        exception_test()
    except Exception as ex:

        #print('test %s' % ex)
        raise

def test1():
    try:
        test()
    except Exception as ex:
        #print('test1 %s' % ex)
        raise

def test2():
    try:
        raise Exception('测试异常')
    except Exception as ex:
        try:
            test1()
        except Exception as e:
            print ('test1:%s' % e)
        print('test2:%s' % ex)
        raise
test2()

