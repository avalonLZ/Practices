/*************************************************************************
	> File Name: equal.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 07 Jan 2019 10:41:41 PM PST
	> Instruction:在一定范围内判断某地址处的值是否全等
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef enum
{
    NO,
    YES
}bool;

//size长度范围内a与b是否相等
bool is_equal(const void *a, const void *b, unsigned int size)
{
    while(size--)
    {
        if(*(int *)(a + size) != *(int *)(b + size))
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    char *a = "1234";
    char *b = "1234";
    printf("a == b? %s\n", is_equal(a, b, strlen(a) + 1) ? "YES" : "NO");
    return 0;
}
