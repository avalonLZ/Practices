/*************************************************************************
	> File Name: test_swap_or.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Wed 13 Feb 2019 09:53:24 PM PST
	> Instruction:使用异或交换两数
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
    int a = 1;
    int b = 11;
    printf("start:a = %d, b = %d\n", a, b);
    a = a ^ b;
    printf("a = %d, b = %d\n", a, b);
    b = a ^ b;
    printf("a = %d, b = %d\n", a, b);
    a = a ^ b;
    printf("end:a = %d, b = %d\n", a, b);
    return 0;
}
