#!/usr/bin/env python
# -*- coding: utf-8 -*-

def test_return():
    return 123,456

def main():
    i,j = test_return()
    print(i)
    print(j)

    k = test_return()
    print(k)

if __name__ == '__main__':
    main()