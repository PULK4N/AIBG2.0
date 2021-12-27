// Fill out your copyright notice in the Description page of Project Settings.


#include "HarvestingCommandFactory.h"

HarvestingCommandFactory::HarvestingCommandFactory()
{
}

HarvestingCommandFactory::~HarvestingCommandFactory()
{
}


TArray<ActionCommand> HarvestingCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
    TArray<ActionCommand> commands;
    if (IsValidCommand(action)) {
        HarvestingActionCommand command(player);
        commands.Add(command);
        return commands;
    }
    else {
        throw "Input is not valid";
    }
}

bool HarvestingCommandFactory::IsValidCommand(FString action) {
    string s = TCHAR_TO_UTF8(*action);
    if (s == "H") {
        return true;
    }
    return false;
}
