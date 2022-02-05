// Fill out your copyright notice in the Description page of Project Settings.


#include "HarvestingActionCommand.h"

HarvestingActionCommand::HarvestingActionCommand()
{
}

HarvestingActionCommand::~HarvestingActionCommand()
{
    UE_LOG(LogTemp, Warning, TEXT("HarvestingActionCommand deleted"));
}

HarvestingActionCommand::HarvestingActionCommand(AGamePlayer* Player)
{
    this->Player = Player;
}

void HarvestingActionCommand::Execute()
{
    if (CanExecute() == false)
        return;
    UE_LOG(LogTemp, Warning, TEXT("Harvesting action executed"));
    Player->HarvestPlants();
}

bool HarvestingActionCommand::CanExecute()
{
    return true;
}
