/*************************************************************************
	> File Name: about_strfun.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Tue 29 Jan 2019 05:08:17 PM PST
	> Instruction:常见str相关函数的使用（具体实现，见glibc）
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define STR_SIZE 15

void my_print(char *funcs, char *funce, char *ch, int size)
{
    int i  = 0;

    if(funcs != NULL)
        printf("****%s*****\n", funcs);

    for(i = 0; i < size; ++i)
    {
        printf("%d ", *(ch + i));
    }

    if(size != 0)
        printf("\n");

    if(funce != NULL)
        printf("****%s*****\n", funce);
}

//字符串拷贝函数
//从打印结果，可知：
//strcpy会拷贝整个strlen(src) + 1的长度
//且最后一个0值的字节，也会被拷贝
void strcpy_func(void)
{
    char *src = "lizhong";
    char dst[STR_SIZE] = {0};
    memset(dst, 1, STR_SIZE);
    
    my_print("strcpy_func_start", NULL, dst, STR_SIZE);
    strcpy(dst, src);
    my_print(NULL, NULL, dst, STR_SIZE);
}

//字符串拼接函数
//由打印可以看出：
//从dst的0值处开始拼接，拼接strlen(src) + 1的长度
//且最后一个0值也会被拷贝
//若dst中0值后依然存在数值，则会被覆盖
void strcat_func(void)
{
    char *src = "lizhong";
    char dst[STR_SIZE] = {0};
    memset(dst, 22, STR_SIZE - 10);
    memset(dst + 10, 22, STR_SIZE - 10);

    my_print("strcat_func_start", NULL, dst, STR_SIZE);
    strcat(dst, src);
    my_print(NULL, NULL, dst, STR_SIZE);
}

//字符串比较函数
//glibc实现是用指针，进行一个个字节的比较
//c1遇到0值（比较完成），或某个字节不等时，则返回当前位置c1-c2的差值
void strcmp_func(void)
{
    char *str1 = "lilili";
    char *str2 = "llllll";

    my_print("strcmp_func_start", NULL, NULL, 0);
    //str1 > str2,strcmp返回正值
    printf("str1:%s > str2:%s is %s\n", str1, str2, strcmp(str1, str2) > 0 ? "TRUE" : "FALSE");

    //str1 < str2,strcmp返回负值
    printf("str1:%s < str2:%s is %s\n", str1, str2, strcmp(str1, str2) < 0 ? "TRUE" : "FALSE");

    //str1 == str2,strcmp返回0
    printf("str1:%s == str2:%s is %s\n", str1, str2, strcmp(str1, str2) == 0 ? "TRUE" : "FALSE");
}

//字符串中查找字符（正序）
//返回匹配到的第一个字符的指针
//找不到则返回0
void strchr_func(void)
{
    char *dst = "llnll";
    char c = 'l';

    my_print("strchr_func_start", NULL, NULL, 0);
    printf("0x%x:%s\n", strchr(dst, c), strchr(dst, c));
    c = 'p';
    printf("0x%x\n", strchr(dst, c));
}

//字符串中查找字符（逆序）
//返回匹配到的第一个字符的指针
//找不到则返回0
void strrchr_func(void)
{
    char *dst = "llnll";
    char c = 'l';

    my_print("strrchr_func_start", NULL, NULL, 0);
    printf("0x%x:%s\n", strrchr(dst, c), strrchr(dst, c));
    c = 'p';
    printf("0x%x\n", strrchr(dst, c));
}

//查找dst中含有src子串的位置
//不包含时，返回NULL
void strstr_func(void)
{
    char *dst = "llnll";
    char *src = "ln";

    my_print("strstr_func_start", NULL, NULL, 0);
    printf("0x%x:%s\n", strstr(dst, src), strstr(dst, src));
    src = "pp";
    printf("0x%x\n", strstr(dst, src));
}

//返回dst开头连续有多少个字符都属于src
//（用的少，不理解有什么用）
void strspn_func(void)
{
    char *dst = "llnll";
    char *src = "ni";
    
    my_print("strspn_func_start", NULL, NULL, 0);
    printf("%d\n", strspn(dst, src));
}

//返回dst开头连续有多少个字符不属于src
//（用的少，不理解有什么用）
void strcspn_func(void)
{
    char *dst = "llnll";
    char *src = "ni";

    my_print("strcspn_func_start", NULL, NULL, 0);
    printf("%d\n", strcspn(dst, src));
}

//返回dst字符串中第一次包含src字符串中的字符的位置
//未找到时，返回NULL
void strpbrk_func(void)
{
    char *dst = "lizhong";
    char *src = "on";

    my_print("strpbrk_func_start", NULL, NULL, 0);
    printf("0x%x:%s\n", strpbrk(dst, src), strpbrk(dst, src));
    src = "il";
    printf("0x%x:%s\n", strpbrk(dst, src), strpbrk(dst, src));
}

//将dst按src指定的字符进行分隔
//使用strtok时需要先计算出dst可以被分隔为几段
//注意：
//1、strtok会修改原始字符串，匹配到的字符会被修改为0值，所以不可以用一个静态地址去分隔
//2、src一定要是字符串的形式
void strtok_func(void)
{
    //char *dst = "192.168.123.11";//core dump
    //这样初始化数组则可将值放入数组中
    char dst[] = "192.168.123.11";
    char *src = ".";
    int count = 0;
    char *index = NULL;

    my_print("strtok_func_start", NULL, NULL, 0);

    //先统计dst可以被分隔为几段（求出要调用几次strtok）
    for(index = dst; *index != 0; ++index)
    {
        if(*index == *src)
            count++;
    }
    count++;

    index = strtok(dst, src);
    count--;
    for(; count > 0; --count)
    {
        printf("count:%d %s\n", count, index);
        index = strtok(NULL, src);
    }
    printf("count:%d %s\n", count, index);
}

int main(int argc, char *argv[])
{
    strcpy_func();
    strcat_func();
    strcmp_func();
    strchr_func();
    strrchr_func();
    strstr_func();
    strspn_func();
    strcspn_func();
    strpbrk_func();
    strtok_func();
    return 0;
}
