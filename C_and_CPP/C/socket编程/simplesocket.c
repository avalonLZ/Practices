/*************************************************************************
	> File Name: simplesocket.c
	> Author:lizhong 
	> Mail: 
	> Created Time: Thu 09 Mar 2017 11:02:12 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>//路径:/usr/include/
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define DPORT 33333
#define SIZE 1000

int Select(int confd)
{
    fd_set fd;
    struct timeval time;
    int ts  = 0;

    time.tv_sec = 0;//0秒
    time.tv_usec = 500;//500毫秒

    FD_ZERO(&fd);
    FD_SET(confd, &fd);

    /*最后一个time参数设置为空意味着阻塞，直到有收到东西*/
    ts = select(confd + 1, &fd, NULL, NULL, NULL);
    
    printf("Select Return:%d\n", ts);
    
    if(ts)
        return 1;
    else
        return 0;
}


int main()
{
    int sfd,confd;
    struct sockaddr_in serveradd;
    char *rebuff;
    char *sebuff;//= "I received the message!";
    int relen = 0,j = 0,k = 0, sel = 0;
    /*初始化Socket,返回socket的文件描述符*/
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if( sfd == -1 )
    {
        printf("Created Socket Error:%s\n", strerror(errno));
        exit(0);
    }
    /*配置本服务器地址参数*/
    memset(&serveradd, 0, sizeof(struct sockaddr_in));
    serveradd.sin_family = AF_INET;
    /*系统自动获取本机IP*/
    serveradd.sin_addr.s_addr = htonl(INADDR_ANY);
    /*设置监听端口为DPORT*/
    serveradd.sin_port = htons(DPORT);
    
    /*Socket和端口绑定*/
    j = bind(sfd, (struct sockaddr*)&serveradd, sizeof(struct sockaddr_in));
    
    if(j == -1)
    {
        printf("Bind Error :%s\n", strerror(errno));
        exit(0);
    }
    j = 0;
    /*开启监听客户端请求，（开闸）*/
    j = listen(sfd, 10);
    
    if(j == -1)
    {
        printf("Listen Error:%s\n", strerror(errno));
        exit(0);
    }
    j= 0;
    printf("***********************Wait Request**********************\n");
       
    /*接受客户端连接,此条语句有阻塞效果*/
     confd = accept(sfd, (struct sockaddr*)NULL, NULL);

    if(confd == -1)
    {
        printf("Accept Error:%s\n", strerror(errno));
        /*出错则结束*/
        return 0;
    }
    while(1)
    {
        /*接收客户端传来的数据*/
        rebuff = malloc(SIZE);
        memset(rebuff, 0, SIZE);
        
        /*注意传入confd，而不是sfd。阻塞，直到有收到东西,收到东西之后用recv函数接收下数据*/
        /*将select函数放到recv函数后将一直返回0，因为recv后缓冲区没有数据了*/
        sel = Select(confd);

        /*flags设置为0值则是阻塞的(默认阻塞)，并且接受完一次数据后接收缓冲区的数据会被清除*/
        /*因为先前socket设置了socket stream(使用面向连接的TCP协议)所以没有数据被丢失,具体表现为：*/
        /*SIZE过小会触发多次接收,每次relen的值最大为SIZE*/
        relen = recv(confd, rebuff, SIZE, 0);

        if(relen != -1 || relen != 0)
        {
            /*可以接收数据，但是数据长度却为0说明客户端断开了TCP连接*/
            if(sel == 1 && relen == 0)
            {
                printf("Socket is close!\n");
                free(rebuff);
                 break;
            }
            else
            {
                printf("Receive Data is :\n********%d:%s****relen:%d********\n", ++k, rebuff, relen);
                sebuff = malloc(strlen("I received the message:") + relen);
                strcpy(sebuff, "I received the message:");//'\0'也会被copy(MSDN上有说明)
                strcat(sebuff, rebuff);
                send(confd, sebuff, strlen(sebuff), 0);
                free(rebuff);
                free(sebuff);
            }
        }
        else
        {
            printf("Receive Error is :%s\n", strerror(errno));
            free(rebuff);
            break;
        }
    }
    return 0;
}
