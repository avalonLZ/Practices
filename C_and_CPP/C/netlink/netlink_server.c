/*************************************************************************
	> File Name: netlink_server.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Thu 31 Jan 2019 05:13:48 PM PST
	> Instruction:netlink server端，用于编译为ko模块，运行在内核中
 ************************************************************************/

//netlink必备头文件
#include<linux/init.h>
#include<linux/module.h>
#include<linux/types.h>
#include<net/sock.h>
#include<linux/netlink.h>

//一些模块信息，必须填写
MODULE_LICENSE("GPL");
MODULE_AUTHOR("lizhong");
MODULE_DESCRIPTION("netlink server");

//NETLINK_L最大只能为31
//否则sock描述符无法创建成功
#define NETLINK_LZ 31
//#define NETLINK_LZ_PORT 111
#define NETLINK_REPLY_DATA "hello"

static struct sock *sk;

void netlink_server_reply(int pid)
{
    struct sk_buff *nl_skb = NULL;
    struct nlmsghdr *nlh = NULL;
    unsigned int msglen = strlen(NETLINK_REPLY_DATA) + 1;

    //创建一个sk_buff的空间
    //GFP_ATOMIC表示在分配内存时不允许睡眠
    nl_skb = nlmsg_new(msglen, GFP_ATOMIC);
    
    if(!nl_skb)
    {
        printk("Netlink server reply sk_buff alloc fail!\n");
        return;
    }

    //填充netlink消息头部
    nlh = nlmsg_put(nl_skb, 0, 0, NETLINK_LZ, msglen, 0);
    
    if(!nlh)
    {
        printk("Netlink server reply nlmsg put fail!\n");
        return;
    }

    memcpy(nlmsg_data(nlh), NETLINK_REPLY_DATA, msglen);
    netlink_unicast(sk, nl_skb, pid, MSG_DONTWAIT);
}

void netlink_server_revmsg(struct sk_buff *skb)
{
    struct nlmsghdr *nlh = nlmsg_hdr(skb);
    char *revmsg = NULL;

    revmsg = NLMSG_DATA(nlh);
    
    if(revmsg)
    {
        printk("Netlink server revmsg:%s, client pid is %d\n", revmsg, nlh->nlmsg_pid);
        netlink_server_reply(nlh->nlmsg_pid);
    }
    else
    {
        printk("Netlink server revmsg NULL!\n");
    }

}

//ko模块exit函数不需要返回值
void netlink_server_exit(void)
{
    if(sk)
    {
        netlink_kernel_release(sk);
        sk = NULL;
    }

    printk("Netlink server exit success!\n");
}

int netlink_server_init(void)
{
    struct netlink_kernel_cfg cfg = {0};
    cfg.input = netlink_server_revmsg;

    //init_net需要查明是什么
    sk = (struct sock*)netlink_kernel_create(&init_net, NETLINK_LZ, &cfg);

    if(!sk)
    {
        printk("Create neklink server fail!\n");
        
        //return负值就代表了此模块初始化失败，lsmod将不会显示
        return -1;
    }

    printk("Neklink server init success!\n");
    return 0;
}

module_init(netlink_server_init);
module_exit(netlink_server_exit);

