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
		vector<string> tiles = getParsedData(action);
		string tile = tiles[1];
        int cordX = stoi( string(1, tile[1]) );
		int cordY = stoi( string(1, tile[3]) );
		commands.Add(new MoleCardActionCommand(player, cordX, cordY, 1, 1));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s: Error - invalid mole action typed"), *player->Name);
	}
	return commands;
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


