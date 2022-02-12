// Fill out your copyright notice in the Description page of Project Settings.


#include "FertilizerCommandFactory.h"
#include "../Defines.h"

FertilizerCommandFactory::FertilizerCommandFactory()
{
}

FertilizerCommandFactory::~FertilizerCommandFactory()
{
}


TArray<ActionCommand*> FertilizerCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
    TArray<ActionCommand*> commands;
    if (IsValidCommand(action)) {
        FertilizerCardActionCommand* command = new FertilizerCardActionCommand(player);
        command->CardID = FERTILIZER_CARD_ID;
        commands.Add(command);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("%s: Error - invalid fertilizer action typed"), *player->Name);
    }
    return commands;
}

bool FertilizerCommandFactory::IsValidCommand(FString action) {
    string s = TCHAR_TO_UTF8(*action);
    if (s == "F") {
        return true;
    }
    return false;
}
