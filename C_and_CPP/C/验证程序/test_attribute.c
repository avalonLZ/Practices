/*************************************************************************
	> File Name: test_attribute.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Wed 18 Jul 2018 11:51:06 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    void *address __attribute__((__aligned__(64)));//锁定了整个结构体的起始地址和长度都是64的整数倍
    char i;
    int j;
    char ii;
    char iii[1];
}test_a_s;

typedef struct
{
    void *address;
    char i;
    int j;
    char ii;
    char iii[1];
}__attribute__((__aligned__(64))) test_a_e;//与test_s效果相同

typedef struct
{
    void *address __attribute__((__aligned__(64)));
    char i;
    int j;//这一段以上是一共占64的整数倍
    char ii __attribute__((__aligned__(64)));
    char iii[1];//这一段以上又占64的整数倍，所以总的至少128个字节，如果两段总的大于128字节，则和test_s定义有相同效果
}test_a_sc;

#pragma pack(1)//每个元素都按最紧凑的1字节对齐
typedef struct
{
    void *address;
    char i;
    int j;
    char ii;
    char iii[1];
}test_p_s;

int main(int argc, char *argv[])
{
    printf("******************************1**********************************\r\n");
    printf("test_a_s size is:%d\r\n", sizeof(test_a_s));
    printf("test_a_e size is:%d\r\n", sizeof(test_a_e));
    printf("test_a_sc size is:%d\r\n", sizeof(test_a_sc));
    printf("test_p_s size is:%d\r\n", sizeof(test_p_s));

    printf("******************************2**********************************\r\n");
    printf("test_a_s char i address is:%p\r\n", &(((test_a_s *)0)->i));
    printf("test_a_s int j address is:%p\r\n", &(((test_a_s *)0)->j));
    printf("test_a_s char ii address is:%p\r\n", &(((test_a_s *)0)->ii));

    printf("******************************3**********************************\r\n");
    printf("test_a_sc char i address is:%p\r\n", &(((test_a_sc *)0)->i));
    printf("test_a_sc int j address is:%p\r\n", &(((test_a_sc *)0)->j));
    printf("test_a_sc char ii address is:%p\r\n", &(((test_a_sc *)0)->ii));

    printf("******************************4**********************************\r\n");
    printf("test_p_s char i address is:%p\r\n", &(((test_p_s *)0)->i));
    printf("test_p_s int j address is:%p\r\n", &(((test_p_s *)0)->j));
    printf("test_p_s char ii address is:%p\r\n", &(((test_p_s *)0)->ii));
    return 0;
}
//由2,3对比可知，attribute加在某结构体中间，可以起到分段对齐的作用
//由2,4对比可知，attribute是在最后填空对齐结构体的(每个元素还是按各自的长度进行对齐)，而pragma是影响每个元素，再每个不对齐的元素后面填空
