// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantingActionCommand.h"
#include "../GameMode/GameMap.h"
#include "../Entity/PlantCard.h"

PlantingActionCommand::PlantingActionCommand()
{
}

PlantingActionCommand::~PlantingActionCommand()
{
    UE_LOG(LogTemp, Warning, TEXT("PlantingActionCommand deleted"));
}

PlantingActionCommand::PlantingActionCommand(int CardId, int CoordinationX, int CoordinationY, AGamePlayer* player)
{
    this->CardId = CardId;
    this->CoordinationX = CoordinationX;
    this->CoordinationY = CoordinationY;
    this->Player = player;
}


void PlantingActionCommand::Execute()
{
    if (CanExecute()) {
        ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
        Player->PlacePlant(CardId, CoordinationX, CoordinationY, tile);
        Player->FindCardById(CardId)->Owned--;
        UE_LOG(LogTemp, Warning, TEXT("Planting action executed"));
    }
}

bool PlantingActionCommand::CanExecute()
{
    if (Player->FindCardById(CardId) == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("Card does not exist"));
        return false;
    }

    if (Player->FindCardById(CardId)->Owned <= 0) {
        UE_LOG(LogTemp, Warning, TEXT("Planting action couldn't execute because player doesn't own enough plant cards"));
        return false;
    }
    if (Player->FindCardById(CardId)->IsA<APlantCard>() == false) {
        UE_LOG(LogTemp, Warning, TEXT("Planting action couldn't execute because card is not a plant card"));
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
