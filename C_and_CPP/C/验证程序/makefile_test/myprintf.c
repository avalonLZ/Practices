/*************************************************************************
	> File Name: myprintf.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年03月12日 星期一 17时33分01秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"aprintf.h"

void myprintf(void)
{
    printf("myprintf_call\r\n");
    aprintf();
    printf("myprintf_function is running!\r\n");
}

