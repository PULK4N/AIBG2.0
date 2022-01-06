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
def inputString(char):
    if char == "1":
        return "L;[0,1];[1,0];[1,1];[1,2]"
    elif char == "2":
        return "C;[0,9];[1,9];[2,9];[3,9];[4,9];[5,9];[6,9]"
    elif char == "2e":
        return "C;[0,9];[1,9];[2,9];[3,9];[4,9];[5,9];[7,9];"
    elif char == "3":
        return "P;[3:[0,0]];[4:[0,1]];[5:[1,0]];[6:[1,1]];[3:[1,2]]"
    elif char == "3e":
        return "P;[3:[0,0]];[4:[0,1]];[5:[1,0]];[6:[1,1]];[3:[1,2]];"
    elif char == "4":
        return "W;[0,0];[0,0];[0,1];[0,1];[1,0];[1,0];[1,0];[1,1];[1,1];[1,1];[1,1];[1,1]"
    elif char == "5":
        return "M;[7,7]"
    elif char == "5e":
        return "M;[7,7];"
    return char

client1 = client_socket(SERVER,PORT_PLAYER_1)
client2 = client_socket(SERVER,PORT_PLAYER_2)
client1.send(input())
client2.send(input())
while True:
    client1.send(inputString(input()))
    client2.recive()
    client2.send(inputString(input()))
    client1.recive()