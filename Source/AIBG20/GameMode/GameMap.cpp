// Fill out your copyright notice in the Description page of Project Settings.

#include "GameMap.h"
#include "../Entity/GamePlayer.h"
#include "../Entity/PlantCard.h"
#include "../Service/SpawnService.h"
#include "../Service/OutputService.h"
#include "../Defines.h"
#include "../Entity/Tile.h"


// Sets default values
AGameMap::AGameMap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

AGameMap::~AGameMap()
{
	UE_LOG(LogTemp, Warning, TEXT("Game map deleted"));
}

// Called when the game starts or when spawned
void AGameMap::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->SpawnActor<ASpawnService>(SpawnServiceToSpawn)->Instantiate(this);
	outputService = GetWorld()->SpawnActor<AOutputService>(AOutputService::StaticClass());
//	Test();//Remove when game starts
}


ATile* AGameMap::FindTile(int x, int y)
{
	return Tiles[x][y];
}

int AGameMap::WhoOwnesTile(int x, int y) {
	ATile* tile = FindTile(x, y);
	if (Player1->Tiles.Find(tile) != INDEX_NONE)
		return 1;
	if (Player2->Tiles.Find(tile) != INDEX_NONE) 
		return 2;
	return 0;
}


void AGameMap::Rain()
{
	if(ANIMATION_IS_ON)
		StartRainAnimation();
	for (TArray<ATile*> tiles : Tiles)
	{
		for (ATile* tile : tiles)
		{
			if (tile->bIsPlanted)
			{
				tile->Plant->Water(RAIN_WATER_DROPS);
			}			
		}
	}
}

void AGameMap::RotPlants()
{
	for (TArray<ATile*> tiles : Tiles)
	{
		for (ATile* tile : tiles)
		{
			if (tile->bIsPlanted)
			{
				if (tile->Plant->DaysToRotCurrent > 0)
				{
					tile->Plant->DaysToRotCurrent--;
				}
				if (tile->Plant->DaysToRotCurrent == 0)
				{
					tile->Plant->Rot();
				}
			}
		}
	}
}

AGamePlayer* AGameMap::GetEnemyPlayer(AGamePlayer* source)
{
	if (source == Player1)
		return Player2;
	return Player1;
}

void AGameMap::DecrementFertilizers()
{
	this->Player1->DecrementFertilizer();
	this->Player2->DecrementFertilizer();
}

int AGameMap::getNumOfTurns()
{
	return turn;
}

void AGameMap::SwitchPlayers()
{
	if (OnTheMovePlayer == Player1) {
		OnTheMovePlayer = Player2;
	}
	else {
		this->NextTurn();
		OnTheMovePlayer = Player1;
		ShowCards();
	}

	if (turn != 0) {
		outputService->SendOutput(this, OnTheMovePlayer);
	}
}

void AGameMap::NextTurn()
{
	turn++;
	if (this->turn % RAIN_DAY == 0)
	{
		Rain();
	}

	RotPlants();
	DecrementFertilizers();
	if (turn >= GAME_END_TURN)
	{
		InputService::getInstance(this)->ClearTimers();
		Player1->EndPlayerInput();
		Player2->EndPlayerInput();
		ShowWinner();
	}
}

TArray<FTileDTO> AGameMap::GenerateMinimalDTO()
{
	TArray<FTileDTO> TileDTOs;
	for (TArray<ATile*> tiles : Tiles) {
		for (ATile* tile : tiles) {
			TileDTOs.Add(tile->GenerateMinimalDTO());
		}
	}
	return TileDTOs;
}