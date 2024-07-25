# -*- coding: utf-8 -*-

import socket
import time
import threading

num = 0

def connect_and_send(server_host, server_port, num):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        client_socket.connect((server_host, server_port))
        print(num, "success connect ",server_host, server_port)

        # 发送消息给服务器
        message = "Hello from client"
        client_socket.send(message.encode())
        print(num, "send ok")

        # 可选：接收服务器响应
        response = client_socket.recv(1024)
        print("server reply:", response.decode())

        #await asyncio.sleep(1)

    except Exception as e:
        print("connect failed, ret:%s", e)

    #finally:
    #    client_socket.close()

def loop():
    server_host = '10.133.15.222'  # 服务器地址，根据实际情况修改
    server_port = 22222        # 服务器端口号，需要与服务器端设置的端口号一致
    global num

    num = num + 1
    connect_and_send(server_host, server_port, num)

def main():
    interval = 1               # 每次尝试连接的间隔时间，单位为秒

    while True:
        threading.Thread(target=loop).start()
        time.sleep(interval)

if __name__ == '__main__':
    main()
