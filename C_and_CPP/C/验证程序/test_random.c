/*************************************************************************
	> File Name: test_random.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Fri 11 Jan 2019 01:42:02 AM PST
	> Instruction:random/rand函数测试
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


unsigned int random_count(void)
{
    unsigned int k = 0;
    int i = 1;

    while(i)
    {
        //因为是伪随机数，又没种子，所以在同一个栈内生成总是相同的
        //i = random() % 10;
        i = rand() % 10;
        k++;
        printf("i = %d\n", i);
    }
    return k;
}

int main(int argc, char *argv[])
{
    printf("k = %d\n", random_count());
    printf("*******************************************\n");
    printf("k = %d\n", random_count());
    return 0;
}
