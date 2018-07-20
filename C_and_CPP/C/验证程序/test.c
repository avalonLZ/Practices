/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月26日 星期三 00时49分30秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
    unsigned char c[5] = {'\0'};
    c[0] = 0;
    c[1] = 4;
    c[2] = 6;
    c[3] = 0;

    printf("%x\n", strtol(c, NULL, 16));
}
