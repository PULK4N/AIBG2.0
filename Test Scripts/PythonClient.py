import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1',8081))

def sendData():
    while True:
        s.send(bytes('C;[0:9];[1:3];[0:3]','utf-8'))
        msg = s.recv(1024)
        print(msg.decode('utf-8'))
        time.sleep(1)
sendData()