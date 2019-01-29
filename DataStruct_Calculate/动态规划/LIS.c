/*************************************************************************
	> File Name: LIS.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 28 Jan 2019 05:58:19 PM PST
	> Instruction:找出最长的上升子序（使用动态规划和不使用动态规划）
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int lis_not_dp(int *array, int array_size)
{
    int *a = NULL;
    int i = 0, j = 0;
    int count = 0;
    int count_last = 0;
    int num = 0;

    a = malloc(sizeof(int) * array_size);
    memcpy(a, array, array_size * sizeof(int));

    for(i = 0; i < array_size; ++i)
    {
        num = a[i];

        for(j = i + 1; j < array_size; ++j)
        {
            if(a[j] > num)
            {
                num = a[j];
                count++;
            }
        }
        count_last = count_last > count ? count_last : count;
        count = 0;
    }

    free(a);
    return count_last + 1;
}

int lis_dp(int *array, int array_size)
{
    int *a = NULL;
    int count = 0;

    a = malloc(sizeof(int) * array_size);
    memcpy(a, array, array_size * sizeof(int));

    return count;
}

int main(int argc, char *argv[])
{
    int test[] = {4,23,1,65,34,23,78,87,43};
    printf("LIS_NOT_DP is:%d\n", lis_not_dp(test, sizeof(test)/sizeof(int)));

    return 0;
}
