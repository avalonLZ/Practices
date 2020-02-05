import re
def match_test():
    test_str = '12 liz li'

    print('match:%s' % re.match('12 \S', test_str,).group())

match_test()