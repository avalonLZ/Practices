#!/usr/bin/env python
# -*- coding: utf-8 -*-



def test(test):
    if test['lz']['l'] == 123:
        test['lzz'] = {'x':444, 'y':555}

def main():
    DIR_TEST = {
        'lz': {
            'l': 123, 'z': 456
        }
    }
    print(DIR_TEST)
    test(DIR_TEST)
    print(DIR_TEST)
    for key, val in DIR_TEST.items():
        print(key,val)
    # print(DIR_TEST.get('lz').get('z'))
    # print(DIR_TEST.get('lz').get('lz'))

import select

def test_dict():
    dict1 = {'fu':{'l':'123', 'z':'456'}}
    dict2 = {}#{'fu':{'l':''}}
    dict1.get('fu', {}).update(dict2.get('fu',{}))
    # dict1.update(dict2)
    print dict1
if __name__ == '__main__':
    # main()
    test_dict()