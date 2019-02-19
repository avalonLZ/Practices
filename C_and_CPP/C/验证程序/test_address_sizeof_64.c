/*************************************************************************
	> File Name: test.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 18 Feb 2019 05:12:19 PM PST
	> Instruction:
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{

    int i = 1;
    long int i_address_64 = (long int)&i;
    
    printf("i_address value is 0x%lx\n", i_address_64);//i_address value is 0x7ffc3ee986f4
    printf("i value is %d\n", *(int *)i_address_64);//i value is 1

    char *ii[] = {"li", "le", "he"};
    printf("char *ii[] sizeof is %d\n", sizeof(ii));//char *ii[] sizeof is 24
    return 0;
}
