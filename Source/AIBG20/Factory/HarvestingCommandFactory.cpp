// Fill out your copyright notice in the Description page of Project Settings.


#include "HarvestingCommandFactory.h"

HarvestingCommandFactory::HarvestingCommandFactory()
{
}

HarvestingCommandFactory::~HarvestingCommandFactory()
{
}


TArray<ActionCommand*> HarvestingCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
    FActionDTO actionDto;
    bool converted = FJsonObjectConverter::JsonObjectStringToUStruct(action, &actionDto, 0, 0);
    TArray<ActionCommand*> commands;

    if (IsValidCommand(actionDto)) {
        commands.Add(new HarvestingActionCommand(player));
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("%s: Error - invalid harvesting action typed"), *player->Name);
    }
    return commands;
}

bool HarvestingCommandFactory::IsValidCommand(FActionDTO actionDto) {
	return true;
}