/*************************************************************************
	> File Name: test_struct_union_sizeof.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Tue 01 Jan 2019 11:28:55 PM PST
	> Instruction:结构体中有联合体时的sizeof
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct student
{
    int i;

    //union大小为union中所有元素成员的最小公倍数
    //此处得找大于14，同时是4、2、1的最小公倍数，16
    union 
    {
        int i;
        char c[14];
        short s;
    }s;//s放到19
    double d;//d得从24开始放，所以整个结构体大小为32
};

int main(int argc, char *argv[])
{
    printf("%d\n", sizeof(struct student));
    return 0;
}


