// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingLandActionCommand.h"
#include "../Entity/GameMap.h"

#define TILE_PRICE 1000

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
		Player->Gold -= TILE_PRICE;
	}
}

bool BuyingLandActionCommand::CanExecute()
{
	if (TileAlreadyOwned())
		return false;
	int GoldLeft = Player->Gold - TILE_PRICE;
	return GoldLeft >= 0;
}

bool BuyingLandActionCommand::TileAlreadyOwned() {
	ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
	return true;
}
