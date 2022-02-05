// Fill out your copyright notice in the Description page of Project Settings.


#include "WateringActionCommand.h"
#include "../Entity/Water.h"
#include "../Entity/GameMap.h"

WateringActionCommand::WateringActionCommand()
{
}

WateringActionCommand::~WateringActionCommand()
{
    UE_LOG(LogTemp, Warning, TEXT("WateringActionCommand deleted"));
}

WateringActionCommand::WateringActionCommand(AGamePlayer* player, int coordinationX, int coordinationY, int cardID, int amount) 
{
    this->Player = player;
    this->CoordinationX = coordinationX;
    this->CoordinationY = coordinationY;
    this->CardID = cardID;
    this->Amount = amount;
}

void WateringActionCommand::Execute()
{
    if (CanExecute()) {
        Player->WaterPlant(Amount, GameMap->FindTile(CoordinationX, CoordinationY));
        Player->FindCardById(CardID)->Owned--;
        UE_LOG(LogTemp, Warning, TEXT("Watering action executed"));
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Watering action couldn't execute"));
    }
}

bool WateringActionCommand::CanExecute()
{
    //does player own that card
    if (Player->FindCardById(CardID)->Owned <= 0) {
        UE_LOG(LogTemp, Warning, TEXT("Watering action couldn't execute because player doesn't have any water"));
        return false;
    }
    ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
    //does player own the tile
    if (Player->Tiles.Find(tile) == INDEX_NONE) {
        UE_LOG(LogTemp, Warning, TEXT("Watering action couldn't execute because player doesn't own the tile"));
        return false;
    }

    if (tile->bIsPlanted == false) {
        UE_LOG(LogTemp, Warning, TEXT("Watering action couldn't execute because tile isn't planted"));
        return false;
    }
    return true;
}
