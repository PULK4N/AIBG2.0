// Fill out your copyright notice in the Description page of Project Settings.


#include "WateringCommandFactory.h"

WateringCommandFactory::WateringCommandFactory()
{
}

WateringCommandFactory::~WateringCommandFactory()
{
}

TArray<ActionCommand> WateringCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
	TArray<ActionCommand> commands;
	if (IsValidCommand(action)) {
		vector<int>::iterator ptr;
		vector<string> tiles = getParsedData(action);
		for (ptr = tiles.begin()+1; ptr < ar.end(); ptr++) {
			string position = *ptr;
			int cordX = stoi( position[1] );
			int cordY = stoi( position[3] );
			WateringActionCommand command(Player, cordX, cordY, AWater, 1);
			commands.Add(command);
		}
		return commands;
	}
	else {
		throw "Input is not valid";
	}
}

bool WateringCommandFactory::IsValidCommand(FString action)
{
	vector<string> result = getParsedData(action);

	if (result.at(0) != "W") {
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


