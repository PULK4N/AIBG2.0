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
	if (CanExecute() == false)
		return;
//	Player->Tiles.add(Tile);
}

bool BuyingLandActionCommand::CanExecute()
{
	if (TileAlreadyOwned()) {
		return false;
	}
	int GoldLeft = Player->Gold - TILE_PRICE;
	return GoldLeft >= 0;
}

bool BuyingLandActionCommand::TileAlreadyOwned() {
	return true;
}