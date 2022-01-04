import socket
import json

class Player:
    def __init__(self,points,gold,fertilizer_active,name,cards):
        pass

def sendData():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(('127.0.0.1',8081))
    s2.connect(('127.0.0.1',8082))
    print('connected')
    i = 0
    while True:
        # print('Input for player1:')
        # s_to_send = input()
        # s.send(bytes(s_to_send,'utf-8'))
        # if i != 0:
        #     msg = s2.recv(2048)
        #     print(msg.decode('utf-8'))
        print('Input for player2:')
        s_to_send = input()
        s2.send(bytes(s_to_send,'utf-8'))
        if i != 0:
            msg = s.recv(2048)
            print(msg.decode('utf-8'))
        i+=1
sendData()