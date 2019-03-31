/*************************************************************************
	> File Name: test_bitcount.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Thu 17 Jan 2019 06:36:38 PM PST
	> Instruction:位统计函数实现
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>

unsigned int BitCount(int var)
{
    unsigned int count_1 = 0;
    unsigned int i = 0;

    for(i = 0; i < sizeof(var) * 8; ++i)
    {
        if((var >> i) & 0x01)
            count_1++;
    }
    return count_1;
}

int main(int argc, char *argv[])
{
    struct timeval start = {0}, end = {0};
    unsigned int i = 0;
    unsigned int res = 0;
    
    res = BitCount(0x8000ffff);

    printf("BitCount = %d\n", res);
    
    return 0;
}
