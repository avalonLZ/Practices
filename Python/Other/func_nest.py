#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main():
    a = 10
    print('#%d' % a)

    def main_1():
        a = 11
        print('#%d' % a)

    main_1()
    print('#%d' % a)

if __name__ == '__main__':
    main()

#Result:
#10
#11
#10