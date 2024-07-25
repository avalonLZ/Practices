# -*- coding: utf-8 -*-

import socket
import threading

def handle_client(client_socket, client_address):
    try:
        print("Accepted connection from", client_address)
        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            print("Received from client", client_address, data.decode())

    except Exception as e:
        print("Exception occurred with client {client_address}: {e}")
#    finally:
#        client_socket.close()
#        print("Connection with {client_address} closed")

def start_server(host, port):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(10240)

    print("Server listening on", host, port)

    while True:
        client_socket, client_address = server_socket.accept()
        # 每次接受到连接请求就创建一个新线程来处理
        client_thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_thread.start()

if __name__ == "__main__":
    HOST = socket.gethostname()
    PORT = 33333

    start_server(HOST, PORT)
