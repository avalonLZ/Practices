/*************************************************************************
	> File Name: two_array_init.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Fri 04 Jan 2019 06:37:23 PM PST
	> Instruction:二维数组初始化试验
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
    int i = 0, j = 0;
    //试验证明，不足的位数自动初始化为0
    int array[3][4] = {{1,2},{3,6}};

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 4; ++j)
        {
            printf("array[%d][%d] value is %d\n", i + 1, j + 1, array[i][j]);
        }
    }

    printf("*****************************************************\n");
    //这样写也会全都初始化为0
    int array1[3][4] = {};

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 4; ++j)
        {
            printf("array1[%d][%d] value is %d\n", i + 1, j + 1, array1[i][j]);
        }
    }
    return 0;
}

