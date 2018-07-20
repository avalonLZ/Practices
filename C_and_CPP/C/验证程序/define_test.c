/*************************************************************************
	> File Name: define_test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年06月20日 星期二 04时24分11秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define VALUE (a) 
#define ADDRESS *((unsigned int*)0x804a024)

int b;

int main()
{
    int a = 10;
    printf("VALUE:%d\n", VALUE);
    VALUE = 100;
    printf("a:%d\n", a);
    printf("address:%p\n", &b);
    ADDRESS = 1;
    printf("ADDRESS:%d\n", ADDRESS);
}
