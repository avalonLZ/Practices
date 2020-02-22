#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main():
    l1 = [None, 0, False, [], {}, '']

    for i in l1:
        print('#%s type is %s' % (i, type(i)))

        if i is True:
            print('#%s is True' % i)
        else:
            print('#%s is False' % i)

        if i == None:
            print('#%s == None' % i)
        else:
            print('#%s != None' % i)
        print('#***********************')

if __name__ == '__main__':
    main()


#Result:
#None type is <type 'NoneType'>
#None is False
#None == None
#***********************
#0 type is <type 'int'>
#0 is False
#0 != None
#***********************
#False type is <type 'bool'>
#False is False
#False != None
#***********************
#[] type is <type 'list'>
#[] is False
#[] != None
#***********************
#{} type is <type 'dict'>
#{} is False
#{} != None
#***********************
# type is <type 'str'>
# is False
# != None
#***********************