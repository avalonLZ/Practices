/*************************************************************************
	> File Name: test_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 07时11分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int sort_f(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int i = 0;
    int list[7] = {36, 89, 2, 112, 3256, 3, 0};
    qsort((void *)list, 7, sizeof(int), sort_f);

    for(i = 0; i < 7; ++i)
        printf("%d\r\n", list[i]);
}
