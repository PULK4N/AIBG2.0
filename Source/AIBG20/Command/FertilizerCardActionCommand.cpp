// Fill out your copyright notice in the Description page of Project Settings.


#include "FertilizerCardActionCommand.h"
#include "../Entity/Fertilizer.h"

FertilizerCardActionCommand::FertilizerCardActionCommand()
{
	Card = &AFertilizer();
}

FertilizerCardActionCommand::~FertilizerCardActionCommand()
{

}

void FertilizerCardActionCommand::Execute()
{
	if (CanExecute()) {
		Player->FertilizerPlant(FindTile());
        Player->FindCardById(Card->Id)->Owned--;
        delete Card;
	}
}

bool FertilizerCardActionCommand::CanExecute()
{
	if (Player->FindCardById(Card->Id)->Owned <= 0)
        return false;
    ATile* tile; /*= GameMap.Instance->FindTile(x, y);*/
    if (Player->Tiles.Find(tile) == INDEX_NONE)
        return false;
    return tile->bIsPlanted;
}

bool FertilizerCardActionCommand::OwnsPlantedTile() {
    //ATile* tile = FindTile();
    //if(Player->Tiles.Find(tile)!=INDEX_NONE)
    //    return tile->bIsPlanted;
    return false;
}

ATile* FertilizerCardActionCommand::FindTile() {
    return nullptr;
}