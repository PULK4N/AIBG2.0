# import socket
# import threading
# import json

# FORMAT = 'utf-8 '
# PORT_PLAYER_1 = 8081
# PORT_PLAYER_2 = 8082

# class Player:
#     def __init__(self,points,gold,fertilizer_active,name,cards):
#         pass

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
        msg = self.client.recv(1024*1024)
        msg = msg.decode(FORMAT)
        #print("len of msg is: {}".format(len(msg)))
        #try:
        #    print(json.loads(msg))
        #except:
        #    print(msg)

client1 = client_socket(SERVER,PORT_PLAYER_1)
client2 = client_socket(SERVER,PORT_PLAYER_2)
#client1.send(input())
#client2.send(input())
while True:
    client2.send('C;[0,9];[1,9];[2,9];[3,9];[4,9];[5,9];[6,9]')
    client2.send('F')
