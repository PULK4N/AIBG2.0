#include <map>
#include <string>
#include <list>

using namespace std;

class Plant {
public:
	int plantId;
	int goldWorth;
	int waterNeeded;

	Plant() {}

	Plant(int plantId, int goldWorth, int waterNeeded)
	{
		this->plantId = plantId;
		this->goldWorth = goldWorth;
		this->waterNeeded = waterNeeded;
	}
	//Plant(map<string, int> values)	{	}

	string getNameFromId()
	{
		switch (this->plantId) {
			case 3:
				return "ANEMONE_FLOWER";
			case 4:
				return "BLUE_JAZZ";
			case 5:
				return "CROCUS_FLOWER";
			case 6:
				return "TULIP";
		}
		return "None";
	}

	string toString()
	{
		return "\n\t\t " + getNameFromId() + ", GoldWorth = " + to_string(this->goldWorth) + ", Water needed = " + to_string(this->waterNeeded) + "\n";
	}
};

class Tile
{
public:
	int x;
	int y;
	bool bIsPlanted;
	bool bIsSpecial;
	Plant plantDTO;
	Tile(int x, int y, bool bIsPlanted, bool bIsSpecial, Plant plantDTO)
	{
		this->x = x;
		this->y = y;
		this->bIsPlanted = bIsPlanted;
		this->bIsSpecial = bIsSpecial;
		this->plantDTO = plantDTO;
	};
	//Tile(map<string, int> values) {	}

	string toString()
	{
		return "\n\tCoordinations = [" + to_string(x) + "," + to_string(y) + "], planted =" + to_string(bIsPlanted) + ", Special tile = " + to_string(bIsSpecial) + " {plantDTO}\n";
	}
};

class Card {
public:
	int cardId;
	int owned;
	Card(int cardId, int owned) {
		this->cardId = cardId;
		this->owned = owned;
	}
	//Card(map<string, int> values){}

	string getNameFromId() {
		switch (this->cardId) {
		case 0:
			return "WATER_CARD";
		case 1:
			return "MOLE_CARD";
		case 2:
			return "FERTILIZER_CARD";
		case 3:
			return "ANEMONE_FLOWERR_CARD";
		case 4:
			return "BLUE_JAZZR_CARD";
		case 5:
			return "CROCUS_FLOWERR_CARD";
		case 6:
			return "TULIPR_CARD";
		default:
			return "";
		}
	}
	string toString()
	{
		return "\n\tOwned " + to_string(this->owned) + " " + this->getNameFromId();
	}
};

class Player {
public:
	int points;
	int gold;
	bool fertilizerActive;
	list<Tile> tiles;
	list<Card> cards;
	Player(int points, int gold, bool fertilizerActive, list<Tile> tiles, list<Card> cards) {
		this->points = points;
		this->gold = gold;
		this->fertilizerActive = fertilizerActive;
		this->tiles = tiles;
		this->cards = cards;
	}
	Player() {}

	//Player(map<string, int> values) {}

	string toString()
	{
		string tilesStr = "";
		string cardStr = "";
		for (Tile t : this->tiles)
			tilesStr.append(t.toString());
		string cards = "";
		for (Card c : this->cards) {
			cardStr.append(c.toString());
		}

		return "\nGold = " + to_string(this->gold) + ", Points = " + to_string(this->points) + " Fertilizer active for " + to_string(this->fertilizerActive) + " turns " + tilesStr + " " + cardStr + "\n";
	}
};

class DTO {
public:
	list<Tile> tiles;
	Player source;
	Player enemy;
	int daysTillRain;

	DTO() {}

	DTO(list<Tile> tiles, Player source, Player enemy, int daysTillRain)
	{
		tiles = tiles;
		source = source;
		enemy = enemy;
		daysTillRain = daysTillRain;
	}

	string toString()
	{
		string tilesStr = "";
		for (Tile t : this->tiles) {
			tilesStr.append(t.toString());
		}
		return "Tiles = " + tilesStr + " \nMy info = \n " + source.toString() + " \nEnemy info = \n " + enemy.toString() + " \nDays till rain = " + to_string(daysTillRain) + "{DaysTillRain}";
	}
};