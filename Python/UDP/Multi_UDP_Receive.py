# -*- coding:utf-8 -*-

import time
import socket

SENDERIP = '169.254.51.246'
MYPORT = 1234 #监听组播组端口
MYGROUP = '225.0.0.77'

def receiver():
    # create a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
    # allow multiple sockets to use the same PORT number
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    # Bind to the port that we know will receive multicast data
    #bind一般用于服务器绑定、监听本地IP和端口，只可以可以绑定本机所具有的IP和端口
    #但在组播中bind应该设置为监听组播IP和其端口，但bind无法设置为绑定、监听非本机的IP（保留IP也不可以被设置为监听对象）
    #所以在组播中必须bind所有ip，和对应组播的端口号
    sock.bind(('0.0.0.0', MYPORT))#留空也可以
    # tell the kernel that we are a multicast socket
    # sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 255)
    # Tell the kernel that we want to add ourselves to a multicast group
    # The address for the multicast group is the third param
    #加入组播组
    status = sock.setsockopt(socket.IPPROTO_IP,
                             socket.IP_ADD_MEMBERSHIP,
                             socket.inet_aton(MYGROUP) + socket.inet_aton(SENDERIP));

    sock.setblocking(0)
    # ts = time.time()
    while 1:
        try:
            data, addr = sock.recvfrom(1024)
        except socket.error, e:
            pass
        else:
            print "Receive data!"

            print "TIME:", time.time()
            print "FROM: ", addr
            print "DATA: ", data


if __name__ == "__main__":
    receiver()