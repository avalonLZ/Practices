/*************************************************************************
	> File Name: point_free.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Fri 21 Dec 2018 06:14:29 PM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void my_free(int *j)
{
    free(j);
    j = NULL;
}

void MY_FREE(int **j)
{
    free(*j);
    *j = NULL;
}

int main()
{
    int *i = malloc(sizeof(int));
    
    //地址依然非NULL(因为是地址值拷贝到变量j)
    *i = 11;
    my_free(i);
    printf("i address is 0x%x\n", i);

    //地址为NULL(因为是将地址值的指针传递赋值给变量j)
    i = malloc(sizeof(int));
    *i = 11;
    MY_FREE(&i);
    printf("i address is 0x%x\n", i);
    
    return 0;
}
