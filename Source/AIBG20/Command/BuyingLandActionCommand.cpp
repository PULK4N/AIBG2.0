// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingLandActionCommand.h"
#include "../Entity/GameMap.h"
#include "../Defines.h"

BuyingLandActionCommand::BuyingLandActionCommand()
{
}

BuyingLandActionCommand::~BuyingLandActionCommand()
{
}

void BuyingLandActionCommand::Execute()
{
	if (CanExecute()) {
		Player->BuyTile(GameMap->FindTile(CoordinationX, CoordinationY));
		Player->Gold -= 1000;
		UE_LOG(LogTemp, Warning, TEXT("Buying land action executed"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Buying land action couldn't execute"));
	}
}

bool BuyingLandActionCommand::CanExecute()
{
	if (TileAlreadyOwned())
		return false;
	int GoldLeft = Player->Gold - 1000;
	return GoldLeft >= 0;
}

bool BuyingLandActionCommand::TileAlreadyOwned() {
	ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
	if (GameMap->Player1->Tiles.Find(tile) == INDEX_NONE && GameMap->Player2->Tiles.Find(tile) == INDEX_NONE) {
		return false;
	}
	return true;
}
