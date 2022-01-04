# import socket
# import threading
# import json

# FORMAT = 'utf-8 '
# PORT_PLAYER_1 = 8081
# PORT_PLAYER_2 = 8082

# class Player:
#     def __init__(self,points,gold,fertilizer_active,name,cards):
#         pass

# def sendData():
#     s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     s2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     s.connect(('127.0.0.1',8081))
#     s2.connect(('127.0.0.1',8082))
#     print('connected')
#     i = 0
#     while True:
#         print('Input for player1:')
#         s_to_send = input()
#         s.send(bytes(s_to_send,FORMAT))
# #        if i != 0:
# #            msg = s2.recv(100000)
# #            print(json.loads(msg))
# #        print('Input for player2:')
#         s_to_send = input()
#         s2.send(bytes(s_to_send,'utf-8'))
# #        if i != 0:
# #            msg = s.recv(100000)
# #            print(json.loads(msg))
# #            print(msg.decode('utf-8'))
#         i+=1
# sendData()

import socket
import threading
import json

FORMAT = 'utf-8 '
PORT_PLAYER_1 = 8081
PORT_PLAYER_2 = 8082
SERVER = '127.0.0.1'
#SERVER = socket.gethostbyname(socket.gethostname())
print(SERVER)


class client_socket:
    def __init__(self,server_ip,server_port):
        self.server_ip = server_ip
        self.server_port = server_port
        self.addr = (server_ip,server_port)
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.connect(self.addr)
        
    def send(self,msg):
        msg = bytes(msg,FORMAT)
        self.client.send(msg)
        #self.client.send(bytes(msg,FORMAT))
        return
    
    def recive(self):
        msg = self.client.recv(1024)
        if msg:
            print(msg)


client1 = client_socket(SERVER,PORT_PLAYER_1)
client2 = client_socket(SERVER,PORT_PLAYER_2)
while True:
    client1.send(input())
    client2.recive()
    client2.send(input())
    client1.recive()