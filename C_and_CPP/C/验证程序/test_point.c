/*************************************************************************
	> File Name: test_point.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年06月03日 星期日 07时17分23秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    char tempstr[1] = {'a'};
    char *pstr = tempstr;
    pstr++; 
    *pstr = 'b';
    printf("%c\r\n", *pstr);
    return 0;
}
