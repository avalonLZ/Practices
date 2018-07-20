/*************************************************************************
	> File Name: movebit.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月01日 星期三 02时04分57秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    unsigned long int i = 0;
    i |= 0x01 << 24;
    printf("%x\r\n", i);
}
