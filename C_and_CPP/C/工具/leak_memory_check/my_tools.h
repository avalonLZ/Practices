/*************************************************************************
	> File Name: my_tools.h
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Tue 07 Aug 2018 12:40:03 AM PDT
 ************************************************************************/

#ifndef _MY_TOOLS_H
#define _MY_TOOLS_H

#define DEBUG_INFOFILEDIR "/root/qos_log/debug_info.txt"
#define DEBUG_INFOSIZEMAX 128

#include<stdio.h>
#include<time.h>

static inline void debug_info2file(char *debug_info)
{
    FILE *fd = NULL;
    time_t now_time;
    struct tm *now_time_tm;
    char now_time_info[DEBUG_INFOSIZEMAX] = {0};

    now_time = time(NULL);
    now_time_tm = localtime(&now_time);
    snprintf(now_time_info, DEBUG_INFOSIZEMAX, "%d-%d-%d %d:%d:%d:\r\n", \
            now_time_tm->tm_year + 1900, \
            now_time_tm->tm_mon + 1, \
            now_time_tm->tm_mday, \
            now_time_tm->tm_hour, \
            now_time_tm->tm_min, \
            now_time_tm->tm_sec);

    if((fd = fopen(DEBUG_INFOFILEDIR, "a+")) == NULL)
        return;

    fprintf(fd, now_time_info); 
    fprintf(fd, debug_info);
    fclose(fd);
}

#define MY_MALLOC(my_msize) ({\
    void *my_mpoint = NULL;\
    char my_malloc_debug_info[DEBUG_INFOSIZEMAX];\
    \
    my_mpoint = malloc(my_msize);\
    snprintf(my_malloc_debug_info, DEBUG_INFOSIZEMAX, "func:%s,line:%d,malloc_size:%d,malloc_ad:%p\r\n", __FUNCTION__, __LINE__, my_msize, my_mpoint);\
    debug_info2file(my_malloc_debug_info);\
    my_mpoint;\
})

#define MY_CALLOC(my_cnmemb, my_csize) ({\
    void *my_cpoint = NULL;\
    char my_calloc_debug_info[DEBUG_INFOSIZEMAX];\
    \
    my_cpoint = calloc(my_cnmemb, my_csize);\
    snprintf(my_calloc_debug_info, DEBUG_INFOSIZEMAX, "func:%s,line:%d,calloc_size:%d,calloc_ad:%p\r\n", __FUNCTION__, __LINE__, my_csize, my_cpoint);\
    debug_info2file(my_calloc_debug_info);\
    my_cpoint;\
})

#define MY_REALLOC(my_repoint_s, my_resize) ({\
    void *my_repoint = NULL;\
    char my_realloc_debug_info[DEBUG_INFOSIZEMAX];\
    \
    my_repoint = realloc(my_repoint_s, my_resize);\
    snprintf(my_realloc_debug_info, DEBUG_INFOSIZEMAX, "func:%s,line:%d,realloc_size:%d,realloc_ad:%p\r\n", __FUNCTION__, __LINE__, my_resize, my_repoint);\
    debug_info2file(my_realloc_debug_info);\
    my_repoint;\
})

#define MY_FREE(my_fpoint) ({\
    char my_free_debug_info[DEBUG_INFOSIZEMAX];\
    \
    snprintf(my_free_debug_info, DEBUG_INFOSIZEMAX, "func:%s,line:%d,free_ad:%p\r\n", __FUNCTION__, __LINE__, my_fpoint);\
    debug_info2file(my_free_debug_info);\
    free(my_fpoint);\
})

#endif
