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

static inline void debug_info2file(char *debug_info)
{
    FILE *fd = NULL;

    if((fd = fopen(DEBUG_INFOFILEDIR, "a+")) == NULL)
        return;

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

#define MY_FREE(my_fpoint) ({\
    char my_free_debug_info[DEBUG_INFOSIZEMAX];\
    \
    snprintf(my_free_debug_info, DEBUG_INFOSIZEMAX, "func:%s,line:%d,free_ad:%p\r\n", __FUNCTION__, __LINE__, my_fpoint);\
    debug_info2file(my_free_debug_info);\
    free(my_fpoint);\
})

#endif
