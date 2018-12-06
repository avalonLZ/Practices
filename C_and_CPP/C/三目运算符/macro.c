/*************************************************************************
	> File Name: macro.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Wed 05 Dec 2018 10:55:24 PM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX(a,b) ((a > b) ? (a) : (b))

int main(int argc, char *argv[])
{
    printf("max is:%d\n", MAX(1,3));
    return 0;
}
