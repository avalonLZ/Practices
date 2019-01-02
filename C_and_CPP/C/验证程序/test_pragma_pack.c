/*************************************************************************
	> File Name: test_pragma_pack.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Tue 01 Jan 2019 11:18:08 PM PST
	> Instruction:pragma_pack实验
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct temp
{
    char c;
    int i;
    short s1;
};

#pragma pack(2)
struct node
{
    char c;
    struct temp t;
    short s;
};

int main(int argc, char *argv[])
{
    printf("%d\n", sizeof(struct node));
    return 0;
}
