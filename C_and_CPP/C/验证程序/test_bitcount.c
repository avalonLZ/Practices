/*************************************************************************
	> File Name: test_bitcount.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Thu 17 Jan 2019 06:36:38 PM PST
	> Instruction:位统计函数实现(统计时间有问题)
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
    //struct timeval start, tv_end;
    struct timeval start = {0}, end = {0};
    unsigned int i = 0;
    unsigned int res = 0;

    //gettimeofday(&start, NULL);

    //for(i = 0; i < 100000; ++i)
        res = BitCount(1234567);

    gettimeofday(&end, NULL);
    printf("BitCount = %d\n", res);
    //printf("end time is %d:%d\n", tv_end.tv_sec, tv_end.tv_usec);
    //printf("%d, %d, %d, %d\n", tv_end.tv_sec, start.tv_sec, tv_end.tv_usec, start.tv_usec);
    printf("消耗时间为:%dms\n", (1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)) / 1000000);
    return 0;
}
