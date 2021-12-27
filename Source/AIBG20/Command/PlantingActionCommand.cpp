// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantingActionCommand.h"
#include "../Entity/GameMap.h"

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
    if (CanExecute()) {
        ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
        Player->PlacePlant(CardID, CoordinationX, CoordinationY, tile);
        Player->FindCardById(CardID)->Owned--;
        UE_LOG(LogTemp, Warning, TEXT("Planting action executed"));
    }
}

bool PlantingActionCommand::CanExecute()
{
    if (Player->FindCardById(CardID)->Owned <= 0) {
        UE_LOG(LogTemp, Warning, TEXT("Planting action couldn't execute because player doesn't own enough plant cards"));
        return false;
    }
    ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
    if (Player->Tiles.Find(tile) == INDEX_NONE) {
        UE_LOG(LogTemp, Warning, TEXT("Planting action couldn't execute because player doesn't own selected tile"));
        return false;
    }
    if (tile->bIsPlanted) {
        UE_LOG(LogTemp, Warning, TEXT("Planting action couldn't execute because tile is already planted"));
        return false;
    }
    return true;
}
