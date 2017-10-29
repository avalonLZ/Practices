# -*- coding: utf-8 -*-

import functools

def ClosePack_test(func):
    def wrapper(*args, **kwargs):
        return func(*args, **kwargs)
    return wrapper




def ClosePack_Sum(input1):
    def wrapper(func):
        @functools.wraps(func)
        def inside(*args, **kwargs):
            print input1 + args[0] + args[1]
            return func(*args, **kwargs)#注意此处需要返回func函数才会执行原函数,否则就相当于重构了，而不是加功能
        return inside
    return wrapper


@ClosePack_Sum(100)
def Sum(a,b):
    print a + b

Sum(1, 4)
print Sum.__name__

print "********************************************************************"

@ClosePack_test
def Sub(a, b):
    if a > b:
        print a - b
    else:
        b - a

Sub(19, 2)
print Sub.__name__