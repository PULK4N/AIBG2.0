// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantingActionCommand.h"

PlantingActionCommand::PlantingActionCommand()
{
}

PlantingActionCommand::~PlantingActionCommand()
{
}

void PlantingActionCommand::Execute()
{
    if (CanExecute() == false)
        return;
}

bool PlantingActionCommand::CanExecute()
{

    return false;
}
