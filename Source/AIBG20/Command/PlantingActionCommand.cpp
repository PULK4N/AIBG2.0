// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantingActionCommand.h"
#include "../Entity/GameMap.h"

PlantingActionCommand::PlantingActionCommand()
{
}

PlantingActionCommand::~PlantingActionCommand()
{
}

void PlantingActionCommand::Execute()
{
    if (CanExecute()) {
        Player->PlacePlant(Card->Id, CoordinationX, CoordinationY);
        Player->FindCardById(Card->Id)->Owned--;
    }
    Card->Destroy();
}

bool PlantingActionCommand::CanExecute()
{
    if (Player->FindCardById(Card->Id)->Owned <= 0)
        return false;
    ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
    if (Player->Tiles.Find(tile) == INDEX_NONE)
        return false;
    return tile->bIsPlanted == false;
}
