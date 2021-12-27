// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingLandActionCommand.h"

#define TILE_PRICE 1000

BuyingLandActionCommand::BuyingLandActionCommand()
{
}

BuyingLandActionCommand::~BuyingLandActionCommand()
{

}

BuyingLandActionCommand::BuyingLandActionCommand(AGamePlayer* Player, int CoordinationX, int CoordinationY, int CardID, int AmountOfCards) 
{
    this->Player = Player;
    this->CoordinationX = CoordinationX;
    this->CoordinationY = CoordinationY;
    this->CardID = CardID;
    this->AmountOfCards = AmountOfCards;
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