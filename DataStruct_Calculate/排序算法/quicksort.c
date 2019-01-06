/*************************************************************************
	> File Name: quicksort.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月05日 星期三 01时40分22秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

unsigned char quick(int *a, unsigned char low, unsigned char high)
{
    //temp为中轴值
    int temp = 0;
    temp = a[low];
    while(low < high)
    {
        /*从后面开始找出小的放前面*/
        while(low < high && a[high] >= temp)
        {
            high--;
        }
        
        if(low < high)
        {
            a[low] = a[high];
            low++;
        }
        
        /*从前面开始找出大的放后面*/
        while(low < high && a[low] < temp)
        {
            low++;
        }

        if(low < high)
        {
            a[high] = a[low];
            high--;
        }
        a[low] = temp;
    }
    return low;
}

void quicksort(int a[], unsigned char low, unsigned char high)
{
    //temp为中轴下标
    unsigned char temp = 0;
    
    if(low < high)
    {
        temp = quick(a, low, high);//先分两半
        quicksort(a, temp+1, high);//对后半部分排序
        quicksort(a, low, temp-1);//对前半部分排序
    } 
}

int main()
{
    int array[] = {37, 19, 43, 22, 22, 89, 26, 92};
    unsigned char i = 0;
    i = sizeof(array)/sizeof(int);
    quicksort(array, 0, i-1);
    
    for(i = 0; i < sizeof(array)/sizeof(int); ++i)
    {
        printf("array[%d] = %d\n", i, array[i]);   
    }
    return 0;
}
