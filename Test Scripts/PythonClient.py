
import socket
import json
from collections import namedtuple
from json import JSONDecoder

##---------------------------------------------------------------
#        
#
class Plant:
    def __init__(self, iD, goldWorth, waterNeeded):
        self.iD = iD
        self.goldWorth = goldWorth
        self.waterNeeded = waterNeeded
    def __init__(self, dictionary):
        for k, v in dictionary.items():
            setattr(self, k, v)
    
    def _get_name_from_iD(self):
        if(self.iD == 3):
            return 'ANEMONE_FLOWER'
        elif(self.iD == 4):
            return 'BLUE_JAZZ'
        elif(self.iD == 5):
            return 'CROCUS_FLOWER'
        elif(self.iD == 6):
            return 'TULIP'
        return 'None'
    def __str__(self) -> str:
        return '\n\t\t{}, GoldWorth = {}, Water needed = {}\n'.format(self._get_name_from_iD(), str(self.goldWorth),  str(self.waterNeeded))
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
    def __init__(self, iD, owned):
        self.iD = iD
        self.owned = owned
    def __init__(self, dictionary):
        for k, v in dictionary.items():
            setattr(self, k, v)

    def _get_name_from_iD(self):
        if(self.iD == 0):
            return 'WATER_CARD'
        elif(self.iD == 1):
            return 'MOLE_CARD'
        elif(self.iD == 2):
            return 'FERTILIZER_CARD'
        elif(self.iD == 3):
            return 'ANEMONE_FLOWERR_CARD'
        elif(self.iD == 4):
            return 'BLUE_JAZZR_CARD'
        elif(self.iD == 5):
            return 'CROCUS_FLOWERR_CARD'
        elif(self.iD == 6):
            return 'TULIPR_CARD'
        return ''
    def __str__(self) -> str:
        return '\n\tOwned ' + str(self.owned) + ' ' + self._get_name_from_iD()

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
    def __init__(self, tiles, source, enemy,daysTillRain):
        self.tiles = tiles
        self.source = source
        self.enemy = enemy
        self.daysTillRain = daysTillRain

    @classmethod
    def from_json(cls,json_string):
        json_dict = json.loads(json_string)
        obj = cls(**json_dict)
        obj.tiles = cls.tiles_dict_to_list(obj.tiles)
        obj.source = Player(obj.source)
        obj.enemy = Player(obj.enemy)
        return obj
    
    @classmethod
    def tiles_dict_to_list(cls,tiles):
        tiles_obj = []
        for tile in tiles:
            tiles_obj.append(Tile(tile))
        return tiles_obj
        

    def __str__(self):
        tiles_str = ''
        for tile in self.tiles:
            tiles_str += str(tile)
        return "Tiles = " + str(tiles_str) + "\nMy info = \n" + self.source.__str__() + "\nEnemy info = \n" + self.enemy.__str__() + "Days till rain = " + str(self.daysTillRain)
#--------------------------------------------------------------- 
def inputString():
    print('Ukucaj jednu od komandi u zavisnost od toga šta želiš da uradiš')
    print('W  - ako želis da zaliješ biljke na određenim poljima (trosis vodu)')
    print('P  - ako želis da posadiš biljke na određenim poljima (Trosis biljke koje posedujes)')
    print('C  - ako želis da kupiš kartice')
    print('F  - ako želis da aktiviraš đubrivo (dupliraš sebi golde narednih 3 poteza)')
    print('H  - ako želis da obereš biljke - dobijas gode')
    print('M  - ako želis da aktiviraš krticu na određenom polju (uništiš biljku ukradeš polje drugom igraču, trosis krtice)')
    print('L  - ako želis da kupiš određeno polje (cena polja 1000 golda)')
    c = input()
    c = c.upper()
    if c == 'W':
        return createWateringCommands()
    elif c == 'P':
        return createPlantingCommands()
    elif c == 'C':
        return createBuyingCommand()
    elif c == 'F':
        return createFertilizerCommand()
    elif c == 'H':
        return createHarvestingCommand()
    elif c == 'M':
        return createMoleCommand()
    elif c == 'L':
        return createBuyingLandCommand()
    return 'H'

def createWateringCommands():
    commands = 'W'
    print('Da biste zavrsili sa kucanjem komandi, samo ukucajte nevaliDnu komandu')
    while True:
        print('Ukucaj kolicinu vode kojom zelis da zalijes polje (od 0 do 9)')
        amount = input()
        if amount < '0' or amount > '9':
            break
        command = ';[' + amount + ':' +  '['
        print('ukucaj koordinatu X na kojoj zelis da zalijes biljku (od 0 do 7)')
        x = input()
        if x < '0' or x > '7':
            break
        command += x + ','
        print('ukucaj koordinatu Y na kojoj zelis da zalijes biljku (od 0 do 7)')
        y = input()
        if y < '0' or y > '7':
            break
        command += y + ']]'
        commands += command
    return commands

def createPlantingCommands():
    commands = 'P'
    print('Da biste zavrsili sa kucanjem komandi, samo ukucajte nevaliDnu komandu')
    while True:
        print('Ukucaj ID biljke koju zelis da zasadis na polje (od 3 do 6)')
        print('3 - Anemone flower (kosta 500, vode potrebno 2, dana do truljenja 5, donosi 2000')
        print('4 - Blue jazz (kosta 1000, vode potrebno 2, dana do truljenja 4, donosi 2500')
        print('5 - Crocus flower(kosta 1000, vode potrebno 5, dana do truljenja 4, donosi 5000')
        print('6 - Tulip(kosta 2000, vode potrebno 9, dana do truljenja 3, donosi 8000')
        iD = input()
        if iD < '3' or iD > '6':
            break
        command = ';[' + iD + ':' +  '['
        print('ukucaj koordinatu X na kojoj zelis da posadis biljku (od 0 do 7)')
        x = input()
        if x < '0' or x > '7':
            break
        command += x + ','
        print('ukucaj koordinatu Y na kojoj zelis da posadis biljku (od 0 do 7)')
        y = input()
        if y < '0' or y > '7':
            break
        command += y + ']]'
        commands += command
    return commands

def createBuyingCommand():
    commands = 'C'
    print('Da biste zavrsili sa kucanjem komandi, samo ukucajte nevaliDnu komandu')
    while True:
        print('Ukucaj ID onoga sto zelis da kupis')
        print('0 - Voda (kosta 200')
        print('1 - Krtica (kosta 10000)')
        print('2 - Đubrivo (kosta 3000)')
        print('3 - Anemone flower (kosta 500, vode potrebno 2, dana do truljenja 5, donosi 2000')
        print('4 - Blue jazz (kosta 500, vode potrebno 2, dana do truljenja 4, donosi 2500')
        print('5 - Crocus flower(kosta 1000, vode potrebno 5, dana do truljenja 4, donosi 5000')
        print('6 - Tulip(kosta 2000, vode potrebno 9, dana do truljenja 3, donosi 8000')
        iD = input()
        if iD < '0' or iD > '6':
            break
        command = ';[' + iD + ','
        print('ukucaj kolicinu(koliko kartica te vrste kupujes))')
        amount = input()
        command += amount + ']'
        commands += command
    return commands

def createMoleCommand():
    command = 'M'
    print('Da biste zavrsili sa kucanjem komandi, samo ukucajte nevaliDnu komandu')
    command += ';['
    print('ukucaj koordinatu X na kojoj zelis da aktiviras krticu (od 0 do 7)')
    x = input()
    if x < '0' or x > '7':
        command += x + ','
    print('ukucaj koordinatu Y na kojoj zelis da aktiviras krticu (od 0 do 7)')
    y = input()
    if y < '0' or y > '7':
        command += y + ']'
    return command

def createBuyingLandCommand():
    commands = 'L'
    print('Da biste zavrsili sa kucanjem komandi, samo ukucajte nevaliDnu komandu')
    while True:
        command = ';['
        print('ukucaj koordinatu X na kojoj zelis da kupis polje (od 0 do 7)')
        x = input()
        if x < '0' or x > '7':
            break
        command += x + ','
        print('ukucaj koordinatu Y na kojoj zelis da kupis polje (od 0 do 7)')
        y = input()
        if y < '0' or y > '7':
            break
        command += y + ']'
        commands += command
    return commands

def createFertilizerCommand():
    return 'F'
def createHarvestingCommand():
    return 'H'
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
            #try:
            dto = DTO.from_json(msg)
            print(str(dto))
            #except:
            #    print(msg)
            self.send(inputString())
#---------------------------------------------------------------

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