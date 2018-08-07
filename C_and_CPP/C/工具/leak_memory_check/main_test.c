/*************************************************************************
	> File Name: main_test.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Tue 07 Aug 2018 12:26:57 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"my_tools.h"

int main(int argc, char *argv[])
{
    char *p = NULL;
    p = MY_MALLOC(sizeof("lizhong")); 
    memcpy(p, "lizhong", sizeof("lizhong"));
    printf("%s\r\n", p);
    MY_FREE(p);
    return 0;
}

