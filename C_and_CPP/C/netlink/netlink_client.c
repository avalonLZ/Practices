/*************************************************************************
	> File Name: netlink_client.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Fri 01 Feb 2019 06:08:54 PM PST
	> Instruction:使用通用sendmsg和revmsg接口，并封装相关api
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<linux/netlink.h>
#include<unistd.h>

#define NETLINK_LZ 31
#define NETLINK_SEND_DATA "world"
#define NETLINK_MSG_DATA_MAX 128

//填充msg中的目的地址相关信息
void pre_send_msg_tokernel(struct msghdr *msgh)
{
    static struct sockaddr_nl dst_addr;
    
    /*填充目的地址信息*/
    dst_addr.nl_family = AF_NETLINK;

	//内核的pid，发往内核此处必须填0
    dst_addr.nl_pid = 0;
    dst_addr.nl_groups = 0;
    
    msgh->msg_name = (void *)&dst_addr;
	msgh->msg_namelen = sizeof(dst_addr);
}

//填充msg中的待发送数据相关信息，并发送数据
void send_msg_tokernel(int fd, struct msghdr *msgh, char *msgdata)
{
    struct iovec iov = {0};
    struct nlmsghdr *nlh = NULL;

    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(NETLINK_MSG_DATA_MAX));

    if(!nlh)
    {
        printf("Malloc nlh fail\n");
        return;
    }
    
    memset(NLMSG_DATA(nlh), 0, NETLINK_MSG_DATA_MAX);
    strcpy(NLMSG_DATA(nlh), msgdata);
    nlh->nlmsg_len = NLMSG_SPACE(NETLINK_MSG_DATA_MAX);
	nlh->nlmsg_pid = getpid();
	nlh->nlmsg_flags = 0;

    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;

    msgh->msg_iov = &iov;
	msgh->msg_iovlen = 1;

    sendmsg(fd, msgh, 0);

    free(nlh);
    nlh = NULL;
}

void pre_rev_msg_fromkernel(int fd)
{
    static struct sockaddr_nl src_addr = {0};
		
	/*用于接收内核reply的消息*/
	src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid();
    src_addr.nl_groups = 0;
    
    if(bind(fd, (struct sockaddr *)&src_addr, sizeof(struct sockaddr_nl)) < 0)
        printf("netlink client bind fail!\n");
}

void rev_msg_fromkernel(int fd, struct msghdr *msgh, char *data)
{
    struct iovec iov = {0};
    struct nlmsghdr *nlh = NULL;
    int size = 0;

    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(NETLINK_MSG_DATA_MAX));

    if(!nlh)
    {
        printf("Malloc nlh fail\n");
        return;
    }

    memset(NLMSG_DATA(nlh), 0, NETLINK_MSG_DATA_MAX);
    nlh->nlmsg_len = NLMSG_SPACE(NETLINK_MSG_DATA_MAX);
	nlh->nlmsg_pid = getpid();
	nlh->nlmsg_flags = 0;

    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;

    msgh->msg_iov = &iov;
	msgh->msg_iovlen = 1;

    while(1)
    {
        size = recvmsg(fd, msgh, 0);

        if(size > 0)
        {
            memcpy(data, (char *) NLMSG_DATA(nlh), size);    
            break;
        }
    }
    
    free(nlh);
    nlh = NULL;
}


int main(int argc, char *argv[])
{
	int netlink_client = 0;
	struct msghdr msg = {0};
    char rev_msg[NETLINK_MSG_DATA_MAX] = {0};
	
	netlink_client = socket(AF_NETLINK, SOCK_DGRAM, NETLINK_LZ);

	if(netlink_client == 0)
	{
	    printf("netlink client create sock fail!\n");
		return -1;
	}

    pre_send_msg_tokernel(&msg);
    pre_rev_msg_fromkernel(netlink_client);
    send_msg_tokernel(netlink_client, &msg, "LIZHONG");
	
    rev_msg_fromkernel(netlink_client, &msg, rev_msg);
    printf("kernel reply:%s\n", rev_msg);
    memset(rev_msg, 0, NETLINK_MSG_DATA_MAX);

    sleep(1);
    send_msg_tokernel(netlink_client, &msg, "hello lizhong");
    rev_msg_fromkernel(netlink_client, &msg, rev_msg);
    printf("kernel reply:%s\n", rev_msg);
    memset(rev_msg, 0, NETLINK_MSG_DATA_MAX);
    
    return 0;
}

