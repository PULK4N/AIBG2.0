// Fill out your copyright notice in the Description page of Project Settings.


#include "HarvestingActionCommand.h"

HarvestingActionCommand::HarvestingActionCommand()
{
}

HarvestingActionCommand::~HarvestingActionCommand()
{
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
