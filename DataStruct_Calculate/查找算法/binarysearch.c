/*************************************************************************
	> File Name: binarysearch.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sat 05 Jan 2019 02:43:42 AM PST
	> Instruction:二分查找算法(只可对有序数列使用)
    需要注意两种特殊情况：
    1、总是往前推（无法比较到第一个元素值，prindex总不变）
    2、总是往后推（无法比较到最后一个元素值，aftindex总不变）
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define SEARCH_VALUE 10


int main(int argc, char *arg[])
{
    int sortarry[] = {1,2,3,4,5,6,7,8,9,10};
    int size = 0;
    int prindex = 0, index = 0, aftindex = 0;
    aftindex = size = sizeof(sortarry)/sizeof(int) - 1;

    while(1)
    {
        //特殊情况1:总是后往前推
        if(aftindex - prindex == 1 && index == aftindex)
        {
            printf("index = prindex = %d\n", prindex);
            break;
        }

        //特殊情况2:总是前往后推
        if(aftindex - prindex == 1 && index == prindex)
        {
            printf("index = aftindex = %d\n", aftindex);
            break;
        }

        index = (aftindex - prindex) / 2 + prindex;

        if(sortarry[index] == SEARCH_VALUE)
        {
            printf("index = %d\n", index);
            break;
        }
        else if(sortarry[index] > SEARCH_VALUE)
        {
            aftindex = index;
        }
        else
        {
            prindex = index;
        }
    }
    return 0;
}
