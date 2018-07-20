/*************************************************************************
	> File Name: select_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月12日 星期三 02时27分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    unsigned char list[] = {44,25,64,3,2,9,47};
    unsigned char size = 0;
    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char max = 0;
    size = sizeof(list);
    printf("size = %d\n", size);
    
    for(i = 0; i < size; ++i)
    {
        max = i;
        for(j = i; j < size -i; ++j)
        {
            if(list[j+1] > list[j])
            {
                max = j+1;
            }
        }
        list[i] = list[max];
    }
    
    for(i = 0; i < size; ++i)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}
