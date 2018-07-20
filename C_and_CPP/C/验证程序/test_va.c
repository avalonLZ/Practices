/*************************************************************************
	> File Name: test_va.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Mon 16 Jul 2018 01:57:12 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdarg.h>

int my_sum(int args, ...)
{
    int i = 0;
    int sum  = 0;
    va_list ps;

    //初始化va参数ps
    va_start(ps, args);

    for(i = 0; i < args; ++i)
    {
        //调用一次ps中的指针自动往后走一个
        sum += va_arg(ps, int);
    }

    va_end(ps);
    return sum;
}

int main(int argc, char *argv[])
{
    printf("1+2+3+4=%d\r\n", my_sum(4, 1, 2, 3, 4));
    return 0;
}
