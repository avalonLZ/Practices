/*************************************************************************
	> File Name: 2arraryhand_test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月22日 星期六 08时35分30秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    unsigned char a1[3][2] = {1,2,3};
    unsigned char i,j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d", a1[i][j]);    
        }
        printf(" ");
    }
}
