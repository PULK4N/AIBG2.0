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
	if (IsNeighbourTile() == false)
		return false;
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

bool BuyingLandActionCommand::IsNeighbourTile() {
	if (CoordinationX < 0)
		return false;
	if (CoordinationY < 0)
		return false;
	
	for (int i = -1; i <= 1; i++) {
		if (CoordinationX == 0 && i == -1) continue;
		for (int j = -1; j <= 1; j++) {
			if (CoordinationY == 0 && j == -1) continue;
			ATile* tile = GameMap->FindTile(CoordinationX + i, CoordinationY + j);
			if (Player->Name == GameMap->Player1->Name) {
				if (GameMap->Player1->Tiles.Find(tile) != INDEX_NONE) {
					return true;
				}
			}
			if (Player->Name == GameMap->Player2->Name) {
				if (GameMap->Player2->Tiles.Find(tile) != INDEX_NONE) {
					return true;
				}
			}
		}
	}
	return false;
}