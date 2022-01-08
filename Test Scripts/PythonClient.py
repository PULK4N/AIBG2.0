
import socket
import json
from collections import namedtuple
from json import JSONDecoder

##---------------------------------------------------------------
#        
#
class Plant:
    def __init__(self, id, goldWorth, waterNeeded):
        self.id = id
        self.goldWorth = goldWorth
        self.waterNeeded = waterNeeded
    def __init__(self, dictionary):
        for k, v in dictionary.items():
            setattr(self, k, v)
    
    def _get_name_from_id(self):
        if(self.id == 3):
            return 'ANEMONE_FLOWER'
        elif(self.id == 4):
            return 'BLUE_JAZZ'
        elif(self.id == 5):
            return 'CROCUS_FLOWER'
        elif(self.id == 6):
            return 'TULIP'
        return 'None'
    def __str__(self) -> str:
        return '\n\t\t{}, GoldWorth = {}, Water needed = {}\n'.format(self._get_name_from_id(), str(self.goldWorth),  str(self.waterNeeded))
#
class Tile:
    def __init__(self, x, y, bIsPlanted, bIsSpecial, plantDTO):
        self.x = x
        self.y = y
        self.bIsPlanted = bIsPlanted
        self.bIsSpecial = bIsSpecial
        self.plantDTO = plantDTO

    def __init__(self, dictionary):
        for k, v in dictionary.items():
            setattr(self, k, v)
        self.plantDTO = Plant(self.plantDTO)
    
    def __str__(self) -> str:
       return '\n\tCoordinations = [{},{}], planted ={}, Special tile = {} {}\n'.format(str(self.x),str(self.y),str(self.bIsPlanted),str(self.bIsSpecial),self.plantDTO.__str__())
#

class Card:
    def __init__(self, id, owned):
        self.id = id
        self.owned = owned
    def __init__(self, dictionary):
        for k, v in dictionary.items():
            setattr(self, k, v)

    def _get_name_from_id(self):
        if(self.id == 0):
            return 'WATER_CARD'
        elif(self.id == 1):
            return 'MOLE_CARD'
        elif(self.id == 2):
            return 'FERTILIZER_CARD'
        elif(self.id == 3):
            return 'ANEMONE_FLOWERR_CARD'
        elif(self.id == 4):
            return 'BLUE_JAZZR_CARD'
        elif(self.id == 5):
            return 'CROCUS_FLOWERR_CARD'
        elif(self.id == 6):
            return 'TULIPR_CARD'
        return ''
    def __str__(self) -> str:
        return '\n\tOwned ' + str(self.owned) + ' ' + self._get_name_from_id()

class Player:
    def __init__(self,points,gold,fertilizerActive,tiles,cards):
        self.points = points
        self.gold = gold
        self.fertilizerActive = fertilizerActive
        self.tiles = tiles
        self.cards = cards

    def __init__(self, dictionary):
        for k, v in dictionary.items():
            setattr(self, k, v)
        Tiles = []
        for tile in self.tiles:
            Tiles.append(Tile(tile))
        self.tiles = Tiles
        Cards = []
        for card in self.cards:
            Cards.append(Card(card))
        self.cards = Cards
    def __str__(self):
        tiles_str = ''
        cards_str = ''
        for tile in self.tiles: 
            tiles_str += str(tile)
        for card in self.cards:
            cards_str += str(card)
        return '\nGold = {}, Points = {} Fertilizer active for {} turns {} {}\n'.format(str(self.gold),str(self.points),str(self.fertilizerActive),tiles_str,cards_str)

class DTO:
    def __init__(self, source, enemy,daysTillRain):
        self.source = source
        self.enemy = enemy
        self.daysTillRain = daysTillRain

    @classmethod
    def from_json(cls,json_string):
        json_dict = json.loads(json_string)
        obj = cls(**json_dict)
        obj.source = Player(obj.source)
        obj.enemy = Player(obj.enemy)
        return obj

    def __str__(self):
        return "My info = \n" + self.source.__str__() + "Enemy info = \n" + self.enemy.__str__() + "Days till rain = " + str(self.daysTillRain)
#--------------------------------------------------------------- 

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
    
    def receive(self):
        while True:
            msg = self.client.recv(8)
            msg = msg.decode(FORMAT)
            msg = self.client.recv(int(msg))

#            try:
            dto = DTO.from_json(msg)
            print(str(dto))
#            except:
#                print(msg)
            self.send(inputString(input()))
#---------------------------------------------------------------
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

def selectPlayer():
    print('Which player are you (1 or 2)')
    playerNum = input()
    if(playerNum == '1'):
        return client_socket(SERVER,PORT_PLAYER_1)
    else:
        return client_socket(SERVER,PORT_PLAYER_2)
        
def InputFor(client):
    print("Input your name")
    client.send(input())
    client.receive()

client = selectPlayer()
InputFor(client)
