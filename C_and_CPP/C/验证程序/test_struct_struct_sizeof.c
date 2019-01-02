/*************************************************************************
	> File Name: test_struct_struct_sizeof.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Tue 01 Jan 2019 11:50:23 PM PST
	> Instruction:结构体嵌套结构体字节对齐测试
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct student
{
    int i;
    char a;

    //找内嵌结构体起始位置
    //最后计算最外层结构体整个大小时
    //需要将内嵌结构体中的元素分开考虑
    //而不能将其视为一个整体
    struct
    {
        double d;
        short s;
    }l;
    short s;
};

int main(int argc, char *argv[])
{
    printf("%d\n", sizeof(struct student));//32
    return 0;
}
