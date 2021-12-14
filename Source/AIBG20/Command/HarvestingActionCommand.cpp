// Fill out your copyright notice in the Description page of Project Settings.


#include "HarvestingActionCommand.h"

HarvestingActionCommand::HarvestingActionCommand()
{
}

HarvestingActionCommand::~HarvestingActionCommand()
{
}

HarvestingActionCommand::HarvestingActionCommand(AGamePlayer* Player)
{
    this->Player = Player;
}

void HarvestingActionCommand::Execute()
{
    if (CanExecute() == false)
        return;

    Player->HarvestPlants();
}

bool HarvestingActionCommand::CanExecute()
{
    return false;
}
