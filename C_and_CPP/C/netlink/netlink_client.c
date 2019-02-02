/*************************************************************************
	> File Name: netlink_client.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Fri 01 Feb 2019 06:08:54 PM PST
	> Instruction:使用通用sendmsg和revmsg接口
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<linux/netlink.h>

#define NETLINK_LZ 31
#define NETLINK_SEND_DATA "world"

void pre_msg(struct sockaddr_nl *dst_addr, struct nlmsghdr *nlh, struct iovec *iov, struct msghdr *msg)
{
    strcpy(NLMSG_DATA(nlh), NETLINK_SEND_DATA);
	iov->iov_base = (void *)nlh;
	iov->iov_len = nlh->nlmsg_len;

	msg->msg_name = (void *)dst_addr;
	msg->msg_namelen = sizeof(struct sockaddr_nl);
	msg->msg_iov = iov;
	msg->msg_iovlen = 1;
}

void pre_send_msg(struct sockaddr_nl *dst_addr, struct nlmsghdr **nlh)
{
    /*填充目的地址信息*/
    dst_addr->nl_family = AF_NETLINK;

	//内核的pid，发往内核此处必须填0
    dst_addr->nl_pid = 0;
    dst_addr->nl_groups = 0;

	/*netlink消息头构建*/
	*nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(strlen(NETLINK_SEND_DATA) + 1));
	(*nlh)->nlmsg_len = NLMSG_SPACE(strlen(NETLINK_SEND_DATA) + 1);
	(*nlh)->nlmsg_pid = getpid();
	(*nlh)->nlmsg_flags = 0;
}

void pre_rev_msg(struct sockaddr_nl *src_addr, int *netlink_client)
{
    int ret = 0;
		
	/*用于接收内核reply的消息*/
	src_addr->nl_family = AF_NETLINK;
    src_addr->nl_pid = getpid();
    src_addr->nl_groups = 0;

	ret = bind(*netlink_client, (struct sockaddr *)src_addr, sizeof(struct sockaddr_nl));
    
    if(ret < 0)
    {
        printf("netlink client bind fail!\n");
		return;
    }
}

int main(int argc, char *argv[])
{
	int netlink_client = 0;
    struct sockaddr_nl src_addr = {0};
	struct sockaddr_nl dst_addr = {0};
	struct iovec iov = {0};
	struct msghdr msg = {0};
	struct nlmsghdr *nlh = NULL;
	
	netlink_client = socket(AF_NETLINK, SOCK_DGRAM, NETLINK_LZ);

	if(netlink_client == 0)
	{
	    printf("netlink client create sock fail!\n");
		return -1;
	}

	pre_send_msg(&dst_addr, &nlh);



	pre_msg(&dst_addr, nlh, &iov, &msg);

	sendmsg(netlink_client, &msg, 0);

	pre_rev_msg(&src_addr, &netlink_client);
    return 0;
}

