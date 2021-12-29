// Fill out your copyright notice in the Description page of Project Settings.


#include "MoleCommandFactory.h"

MoleCommandFactory::MoleCommandFactory()
{
}

MoleCommandFactory::~MoleCommandFactory()
{
}

TArray<ActionCommand*> MoleCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
	TArray<ActionCommand*> commands;
	if (IsValidCommand(action)) {
		vector<int>::iterator ptr;
		vector<string> tiles = getParsedData(action);
        int cordX = stoi( string(1, tiles.at(0)[1]) );
		int cordY = stoi( string(1, tiles.at(0)[3]) );
		commands.Add(new MoleCardActionCommand(player, cordX, cordY, 1, 1));
		return commands;
	}
	else {
		throw "Input is not valid";
	}
}

bool MoleCommandFactory::IsValidCommand(FString action)
{
	vector<string> result = getParsedData(action);

	if (result.at(0) != "M") {
		return false;
	}
    if (result.size() != 2) {
        return false;
    }
	for (int i = 1; i < result.size(); i++) {
		string elem = result.at(i);
		if (elem.length()!=5) {
			return false;
		}
		if ((elem[0] != '[') || (elem[4] != ']') || (elem[2] != ',')) {
			return false;
		}
		if (!isdigit(elem[1]) || (elem[1] - '0') >= 8 || !isdigit(elem[3]) || (elem[3] - '0') >= 8) {
			return false;
		}
	}
	return true;
}


