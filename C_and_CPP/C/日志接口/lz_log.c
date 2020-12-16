/*************************************************************************
	> File Name: lz_log.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Wed 16 Dec 2020 07:36:50 AM PST
	> Instruction:
 ************************************************************************/
#include<stdio.h>
#include<string.h>

void lz_log(char *content)
{
    #define BUF_SIZE 128
    char buf[BUF_SIZE] = {0};
    char *log_path = "/home/lz/Desktop/lz_log";
    FILE *fd = fopen(log_path, "a");

    memcpy(buf, content, BUF_SIZE - 1);
    fprintf(fd, "lzlzlz*****content:%s******\n", buf);

    fflush(fd);
    fclose(fd);
}

int main()
{
    lz_log("123123");
    lz_log("5777");
    return 0;
}
