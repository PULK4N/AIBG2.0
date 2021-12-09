// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingLandActionCommand.h"

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
		// or Player->BuyTile(x, y, FindTile());
		Player->Tiles.Add(FindTile());
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
	ATile* tile; /*= GameMap.Instance->FindTile(CoordinationX, CoordinationY);*/
	return true;
}

ATile* BuyingLandActionCommand::FindTile() {
    return nullptr;
}