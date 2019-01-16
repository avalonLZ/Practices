/*************************************************************************
	> File Name: main.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Tue 15 Jan 2019 06:50:25 PM PST
	> Instruction:静态链接库试验
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "my_printf.h"

int main(int argc, char *argv[])
{
    char *a = "123";
    my_printf(a);
    return 0;
}

