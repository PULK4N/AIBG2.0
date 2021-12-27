// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantingActionCommand.h"

PlantingActionCommand::PlantingActionCommand()
{
}

PlantingActionCommand::~PlantingActionCommand()
{
}

PlantingActionCommand::PlantingActionCommand(int CardID, int CoordinationX, int CoordinationY)
{
    this->CardID = CardID;
    this->CoordinationX = CoordinationX;
    this->CoordinationY = CoordinationY;
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
