/*************************************************************************
	> File Name: test_malloc_sizeof.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年02月28日 星期三 16时28分39秒
 ************************************************************************/
#include<string.h>
#include<stdlib.h>
#include<stdio.h>


int main(void)
{
    char p[] = "hello world!";
    char *pp;
    pp = (char *)malloc(100);
    printf("p sizeof:%d\r\n", sizeof(p));
    printf("pp sizeof:%d\r\n", sizeof(pp));
    printf("*pp sizeof:%d\r\n", sizeof(*pp));
    return 0;
}
