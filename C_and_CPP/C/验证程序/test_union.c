/*************************************************************************
	> File Name: test_union.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Tue 01 Jan 2019 10:40:50 PM PST
	> Instruction:union验证例程
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


union u_student
{
    unsigned short int zz;
    char z[2]; 
};

struct student
{
    unsigned short int i;
    union u_student ii;    
};


int main(int argc, char *argv[])
{
    struct student t = {0};
    t.i = 0x1234;
    
    //切记，union是union内部的变量共用内存，而不是和外部的变量
    printf("0x%x\n", t.ii.z[0]);
    printf("0x%x\n", t.ii.z[1]);

    printf("******************************************\n");

    t.ii.zz = 0x1234;
    printf("0x%x\n", t.ii.z[0]);
    printf("0x%x\n", t.ii.z[1]);

    return 0;
}
