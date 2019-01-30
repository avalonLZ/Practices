/*************************************************************************
	> File Name: sanmu_plusplus.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Wed 30 Jan 2019 06:23:19 AM PST
	> Instruction:三目运算符结合++试验
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
    int i = 0;

    printf("i++ > 0?\n%s\n", i++ > 0 ? "YES" : "NO");
    i = 0;
    printf("++i > 0?\n%s\n", ++i > 0 ? "YES" : "NO");
    return 0;
}
