// Fill out your copyright notice in the Description page of Project Settings.


#include "WateringActionCommand.h"
#include "../Entity/Water.h"

WateringActionCommand::WateringActionCommand()
{
    Card = &AWater(); // might be not work
}

WateringActionCommand::~WateringActionCommand()
{
}

void WateringActionCommand::Execute()
{
    if (CanExecute()) {
        Player->WaterPlant(1, FindTile());
        Player->FindCardById(Card->Id)->Owned--;
        delete Card;
    }
}

bool WateringActionCommand::CanExecute()
{
    if (Player->FindCardById(Card->Id)->Owned <= 0)
        return false;
    ATile* tile; /*= GameMap.Instance->FindTile(x, y);*/
    if (Player->Tiles.Find(tile) == INDEX_NONE)
        return false;
    if (tile->bIsPlanted)
        return false;
    return true;
}

bool WateringActionCommand::OwnsPlantedTile() {
    //ATile* tile = FindTile();
    //if(Player->Tiles.Find(tile)!=INDEX_NONE)
    //    return tile->bIsPlanted;
    return false;
}

ATile* WateringActionCommand::FindTile() {
    return nullptr;
}
