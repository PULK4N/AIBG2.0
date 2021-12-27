// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingLandCommandFactory.h"

BuyingLandCommandFactory::BuyingLandCommandFactory()
{
}

BuyingLandCommandFactory::~BuyingLandCommandFactory()
{
}

TArray<ActionCommand> BuyingLandCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
    TArray<ActionCommand> commands;
	if (IsValidCommand(action)) {
		vector<string> tiles = getParsedData(action);
		vector<string>::iterator it = tiles.begin();
		++it;
		while (it != tiles.end()) {
			string position = *it;
			int cordX = stoi(string(1, position[1]));
			int cordY = stoi(string(1, position[3]));
			BuyingLandActionCommand command(player, cordX, cordY, plantCard, 1);
			commands.Add(command);
		}
		return commands;
	}
	else {
		throw "Input is not valid";
	}
}

bool BuyingLandCommandFactory::IsValidCommand(FString action) {
    vector<string> result = getParsedData(action);

	if (result.at(0) != "L") {
		return false;
	}
	for (int i = 1; i <= result.size(); i++) {
		string elem = result.at(i);
        if (elem.length()!=5) {
			return false;
		}
		if ((elem[0] != '[') || (elem[4] != ']') || (elem[2] != ',')) {
			return false;
		}
		if (!isalpha(elem[1]) || elem[1] >= 8 || !isalpha(elem[3]) || elem[3] >= 8) {
			return false;
		}
	}
	return true;
}

