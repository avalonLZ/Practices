/*************************************************************************
    > File Name: server_process.c
    > Author:lizhong
    > Mail:423810942@qq.com
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
#include<asm-generic/fcntl.h>

const static char *g_Path = "/tmp/lz_socket";

int main(int arg, char *argv[])
{
    struct sockaddr_un sa;
    int sfd, confd;
    unsigned int len;
    unsigned int recvsize = 0;
    char buf[1024] = {0};

    memset(&sa, 0, sizeof(sa));
    
    sfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    
    if(sfd < 0)
    {
        printf("sfd get error!\r\n");
    }

    sa.sun_family = AF_LOCAL;
    strncpy(sa.sun_path, g_Path, strlen(g_Path) + 1);
    len = offsetof(struct sockaddr_un, sun_path) + strlen(g_Path);

    /*直接用sizeof(sa)也可以*/
    if(bind(sfd, (struct sockaddr *)&sa, len) == -1)
    {
        printf("bind error!\r\n");
        close(sfd);
        return 1;
    }

    if(listen(sfd, 1) == -1)
    {
        printf("listen error!\r\n");
        close(sfd);
        return 1;
    }

    /*默认阻塞，使用fcntl可将其设置为非阻塞,recv函数也一样默认阻塞*/
    confd = accept(sfd, (struct sockaddr *)NULL, NULL);
    
    if(confd < 0)
    {    
        printf("Server Connect error!\r\n");
        close(sfd);
        return 1;
    }

    printf("Server Connect OK!\r\n");
    
    /*配置为O_NONBLOCK,但是首次接收依然是阻塞状态，接收过一次后将变为非阻塞状态*/
    //if(fcntl(confd, F_SETFL, O_NONBLOCK) < 0)
    //{
    //    printf("fcntl error!\r\n");
    //    close(sfd);
    //    close(confd);
    //    return 1;
    //}

    while(1)
    {
        if(recv(confd, buf, sizeof(buf), 0) == -1)
        {
            printf("recv error\r\n");
            //close(sfd);
            //close(confd);
            //return 1;
        }

        printf("recv:%s\r\n", buf);
        memset(buf, 0, sizeof(buf));
    }
    
    close(sfd);
    close(confd);
    return 0;
}

