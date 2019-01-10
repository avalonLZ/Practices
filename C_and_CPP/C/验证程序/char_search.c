/*************************************************************************
	> File Name: search.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Wed 09 Jan 2019 11:30:21 PM PST
	> Instruction:从abcdefg中查找是否含有cef三个字母，且要求出现的顺序相同
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef enum 
{
    NO,
    YES
}bool;

bool search(char *z, char *s)
{
    unsigned int z_index = 0;
    unsigned int s_index = 0;
    unsigned int index = 0;

    for(; s_index < strlen(s); ++s_index)
    {
        for(; z_index < strlen(z); ++z_index)
        {
            if(z[z_index] == s[s_index])
            {
                index = z_index;
                break;
            }
        }
    }

    if(z[index] == s[strlen(s) - 1])
        return 1;
    else
        return 0;
}

int main(int argc, int argv[])
{
    char *s = "gf";
    char *zs = "abcdefg";

    printf("是否符合要求:%s\n", search(zs, s) ? "YES" : "NO");

    return 0;
}
