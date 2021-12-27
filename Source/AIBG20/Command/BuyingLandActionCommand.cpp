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

BuyingLandActionCommand::BuyingLandActionCommand(AGamePlayer* Player, int CoordinationX, int CoordinationY, int AmountOfCards) 
{
    this->Player = Player;
    this->CoordinationX = CoordinationX;
    this->CoordinationY = CoordinationY;
    this->AmountOfCards = AmountOfCards;
}

void BuyingLandActionCommand::Execute()
{
	if (CanExecute()) {
		BuyTile();
		UE_LOG(LogTemp, Warning, TEXT("Buying land action executed"));
	}
}

bool BuyingLandActionCommand::CanExecute()
{
	if ((Player->Gold - 1000) < 0) {
		UE_LOG(LogTemp, Warning, TEXT("Buying land action couldn't execute because player doesn't have enough money"));
		return false;
	}
	if (TileAlreadyOwned()) {
		UE_LOG(LogTemp, Warning, TEXT("Buying land action couldn't execute because tile is already owned tile X: %d, Y:%d"), CoordinationX, CoordinationY);
		return false;
	}
	if (IsNeighbourTile() == false) {
		UE_LOG(LogTemp, Warning, TEXT("Buying land action couldn't execute because it's not a neighbooring tile X: %d, Y:%d"), CoordinationX, CoordinationY);
		return false;
	}
	return true;
}

bool BuyingLandActionCommand::TileAlreadyOwned() {
	ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
	if (GameMap->Player1->Tiles.Find(tile) == INDEX_NONE && GameMap->Player2->Tiles.Find(tile) == INDEX_NONE) {
		return false;
	}
	return true;
}

bool BuyingLandActionCommand::IsNeighbourTile() {
	if (CoordinationX < 0 || CoordinationX > 7)
		return false;
	if (CoordinationY < 0 || CoordinationY > 7)
		return false;
	
	for (int i = -1; i <= 1; i++) {
		if ((CoordinationX == 0 && i == -1) || (CoordinationX == 7 && i == 1)) continue;
		for (int j = -1; j <= 1; j++) {
			if ((CoordinationY == 0 && j == -1) || (CoordinationY == 7 && j == 1)) continue;
			ATile* tile = GameMap->FindTile(CoordinationX + i, CoordinationY + j);
			if (Player == GameMap->Player1) {
				if (GameMap->Player1->Tiles.Find(tile) != INDEX_NONE) {
					return true;
				}
			}
			if (Player == GameMap->Player2) {
				if (GameMap->Player2->Tiles.Find(tile) != INDEX_NONE) {
					return true;
				}
			}
		}
	}
	return false;
}


void BuyingLandActionCommand::BuyTile() {
	ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
	Player->Gold -= TILE_COST;
	Player->BuyTile(tile);
	ChangeTileLookByOwner(tile);
}

void BuyingLandActionCommand::ChangeTileLookByOwner(ATile* tile) {
	if (Player == GameMap->Player1) {
		tile->ChangeMeshComponent(ATile::PLAYER_1);
	}
	else {
		tile->ChangeMeshComponent(ATile::PLAYER_2);
	}
}