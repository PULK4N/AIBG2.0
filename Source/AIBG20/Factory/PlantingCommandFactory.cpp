// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantingCommandFactory.h"

PlantingCommandFactory::PlantingCommandFactory()
{
}

PlantingCommandFactory::~PlantingCommandFactory()
{
}

bool PlantingCommandFactory::IsValidCommand(FString action) 
{
    vector<string> result = getParsedData(action);

	if (result.at(0) != "P") {
		return false;
	}
	for (int i = 1; i < result.size(); i++) {
		string elem = result.at(i);
		if (elem.length()!=9) {
			return false;
		}
		if ((elem[0] != '[') || (elem[2] != ':') || (elem[3] != '[') || (elem[5] != ',') || (elem[7] != ']') || (elem[8] != ']')) {
			return false;
		}
		if (!isdigit(elem[1]) || !isdigit(elem[4]) || !isdigit(elem[6]) || (elem[4] - '0')>7 || (elem[6] - '0')>7) {
            return false;
		}
	}
	return true;
}

TArray<ActionCommand*> PlantingCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
    TArray<ActionCommand*> commands;
	if (IsValidCommand(action)) {
		vector<string> tiles = getParsedData(action);
		vector<string>::iterator it = tiles.begin();
		++it;
		while (it != tiles.end()) {
			string position = *it;
            int cardID = stoi(string(1, position[1])); 
			int cordX = stoi(string(1, position[4]));
			int cordY = stoi(string(1, position[6]));
			commands.Add(new PlantingActionCommand(cardID, cordX, cordY, player));
			++it;
		}
		return commands;
	}
	else {
		throw "Input is not valid";
	}
}
