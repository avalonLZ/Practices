/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 19时15分12秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include"callbacket.h"

int main()
{
    unsigned char i = 0;
    /*定义一个Call_Backet类型的回调函数*/
    Call_Backet First = First_Function;
    i = (*First)(1,5);
    printf("%d\n", i);

    Second = First_Function;
    i = (*Second)(3, 7);
    printf("%d\n", i);
}
