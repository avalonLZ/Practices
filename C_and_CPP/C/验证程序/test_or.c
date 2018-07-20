/*************************************************************************
	> File Name: test_or.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Sun 24 Jun 2018 06:53:07 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main(int argc, char *argv[])
{
    unsigned char i = 10;
    printf("i = %d\r\n", i);
    printf("i ^= %d\r\n", i ^ 0xff);
    printf("i ^^= %d\r\n ", i ^ 0xff ^ 0xff);
    return 0;
}
