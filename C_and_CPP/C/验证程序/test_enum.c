/*************************************************************************
	> File Name: test_enum.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Thu 22 Nov 2018 12:55:59 AM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef enum test
{
    ONE,
    TWO,
    THREE
}test_e;

int main(int argc, char *argv[])
{
    test_e t = TWO;
    
    printf("t value is:%d\n", t);

    return 0;
}
