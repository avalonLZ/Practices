/*************************************************************************
	> File Name: dump_stack.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Fri 19 Feb 2021 11:07:48 PM PST
	> Instruction:编译gcc dump_stack.c -rdynamic 
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include<execinfo.h>
#define STACK_DEEP_MAX 128

void dump_stack()
{
    int stack_deep = 0;
    void *content[STACK_DEEP_MAX] = {0};
    char **content_str = NULL;

    stack_deep = backtrace(content, STACK_DEEP_MAX);
    content_str = (char **)backtrace_symbols(content, stack_deep);
    int i = 0;
    for (i = 0; i < stack_deep; i++)
    {
        printf("%d:%s\n", i, content_str[i]);
    }
    printf("*****************************\n");
    for (i = 0; i < stack_deep; i++)
    {
        printf("%d:%s\n", i, (char *)content[i]);
    }
    free(content_str);
}

void stack_three()
{
    printf("stack three start\n");
    dump_stack();
    printf("stack three end\n");
}

void stack_two()
{
    printf("stack two start\n");
    stack_three();
    printf("stack two end\n");
}

void stack_one()
{
    printf("stack one start\n");
    stack_two();
    printf("stack one end\n");
}

int main(int argc, char *argv[])
{
    printf("main start\n");
    stack_one();
    printf("main end\n");
    return 0;
}

