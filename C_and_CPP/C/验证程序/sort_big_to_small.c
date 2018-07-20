/*************************************************************************
	> File Name: sort_big_to_small.c
	> Author: 
	> Mail: 
	> Created Time: 2017年08月06日 星期日 17时48分13秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    unsigned int a[10] = {98,22,22,53,64,12,90,43,68,66};
    unsigned char i,j,k;

    for(i= 0; i < 10; ++i)
    {
        k = i;
        
        for(j = i; j < 10; ++j)
        {
            if(a[k] < a[j])
                k = j;
        }
        if(k != i)
        {
            a[i] ^= a[k];
            a[k] = a[i]^a[k];
            a[i] ^= a[k];
        }
    }
    for(i = 0; i < 10; ++i)
        printf("%d\n", a[i]);
}
