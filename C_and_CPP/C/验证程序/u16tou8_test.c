/*************************************************************************
	> File Name: u16tou8.c
	> Author: 
	> Mail: 
	> Created Time: 2017年06月20日 星期二 17时58分48秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
    unsigned short int i = 255;
    printf("u16tou8:%02x\n", (unsigned char)(i));
    printf("u16tou8:%02x\n", (unsigned char)(i >> 8));
    printf("u16tou8:%02x\n", (unsigned char)(i << 8));
}
