/*************************************************************************
	> File Name: same_str.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Wed 20 Feb 2019 10:09:24 PM PST
	> Instruction:查找两字符串中的最长的相同子串
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SAMESTRLEN 128
#define STR2 "lizhong"
#define STR1 "xzhoi"

int Search_SameStr2(char *str1, char *str2)
{
    int count = 0;
    char *chr1 = str1++;
    char *chr2 = str2++;

    while(*chr1 != 0 || *chr2 !=0)
    {
        if(*chr1 == *chr2)
            count++;
        else
            break;

        chr1 = str1++;
        chr2 = str2++;
    }

    return count;
}

void Search_SameStr(char *samestr, char *str1, char *str2)
{
    int index = 0;
    int size = 0;
    int temp_size = 0;
    int i = 0;
    int j = 0;

    for(i = 0; str1[i] != 0; ++i)
    {
        for(j = 0; str2[j] != 0; ++j)
        {
            if(str1[i] == str2[j])
            {
                //相同时，单独进行统计，之后有几个相同的字符
                //这样不会影响目前的游标
                temp_size = Search_SameStr2(str1 + i, str2 + j);

                if(size < temp_size)
                {
                    size = temp_size;
                    index = j;
                }
            }
        }
    }
    memcpy(samestr, str2 + index, size);
}

int main(int argc, char *argv[])
{
    char samestr[MAX_SAMESTRLEN] = {0};

    Search_SameStr(samestr, STR1, STR2);
    
    printf("max len same str is %s\n", samestr);

    return 0;
}
