/*************************************************************************
	> File Name: client_process.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Sun 10 Jun 2018 06:16:24 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stddef.h>
#include<linux/un.h>

const static char *g_Path = "/tmp/lz_socket";

int main()
{
    int sfd, confd;
    struct sockaddr_un sa;
    unsigned int len;

    memset(&sa, 0, sizeof(struct sockaddr_un));

    //初始化一个socket对象
    sfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    sa.sun_family = AF_LOCAL;
    strncpy(sa.sun_path, g_Path, strlen(g_Path) + 1);
    len = offsetof(struct sockaddr_un, sun_path) + strlen(g_Path); 

    if(connect(sfd, (struct sockaddr *)&sa, sizeof(sa)) == -1)
    {
        printf("Client Connetc error!\r\n");
        close(sfd);
        return 1;
    }
   
    while(1)
    {
        if(send(sfd, "123", strlen("123") + 1, 0) == -1)
        {
            printf("send error!\r\n");
            return 1;
        }

        sleep(1);
    }

    close(sfd);
    return 0;
}

