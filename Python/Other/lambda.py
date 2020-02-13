#! /usr/bin/env python
# -*- coding: utf-8 -*-

class xy(object):
    x = 5
    y = 2

#lambda_test_1
def lambda_1():
    print('lambda_test_1...')
    #lambda返回是一个完成闭包的函数
    lambda_func_1 = lambda x,y : x * y
    #需要一次调用才可输出返回值
    print(lambda_func_1(xy.x, xy.y))

#lambda_test_2
def l2(x, y):
    return x + y + 9

def lambda_2():
    print('lambda_test_2...')
    #一般不这样玩,一般就是向lambda_1那样，封装一个非嵌套函数
    lambda_func_2 = lambda x,y : l2(x, y)
    print(lambda_func_2(xy.x, xy.y))

if __name__ == '__main__':
    lambda_1()
    lambda_2()