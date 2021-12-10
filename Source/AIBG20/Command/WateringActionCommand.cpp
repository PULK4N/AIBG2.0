// Fill out your copyright notice in the Description page of Project Settings.


#include "WateringActionCommand.h"
#include "../Entity/Water.h"
#include "../Entity/GameMap.h"

WateringActionCommand::WateringActionCommand()
{
}

WateringActionCommand::~WateringActionCommand()
{
}

void WateringActionCommand::Execute()
{
    FActorSpawnParameters Spawnparams;
    AWater water;
    Card = GameMap->GetWorld()->SpawnActor<AWater>(water.GetClass(), Spawnparams);
    if (CanExecute()) {
        Player->WaterPlant(1, GameMap->FindTile(CoordinationX, CoordinationY));
        Player->FindCardById(Card->Id)->Owned--;
    }
    Card->Destroy();
}

bool WateringActionCommand::CanExecute()
{
    //does player own that card
    if (Player->FindCardById(Card->Id)->Owned <= 0)
        return false;
    ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
    //does player own the tile
    if (Player->Tiles.Find(tile) == INDEX_NONE)
        return false;
    //can execute if it is planted
    return tile->bIsPlanted;
}
