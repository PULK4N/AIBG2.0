// Fill out your copyright notice in the Description page of Project Settings.

#include "GameMap.h"
#include "GamePlayer.h"
#include "PlantCard.h"
#include "../Service/SpawnService.h"
#include "../Defines.h"


// Sets default values
AGameMap::AGameMap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AGameMap::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->SpawnActor<ASpawnService>(SpawnServiceToSpawn)->Instantiate(this);
	OnTheMovePlayer = Player1;
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

/* TEST function
void AGameMap::Test() {
	BuyingLandActionCommand* buyingCommand = new BuyingLandActionCommand();
	buyingCommand->Player = Player2;
	buyingCommand->CoordinationX = 7;
	buyingCommand->CoordinationY = 7;
	buyingCommand->Execute();
	buyingCommand->CoordinationX = 6;
	buyingCommand->CoordinationY = 6;
	buyingCommand->Execute();
	buyingCommand->CoordinationX = 6;
	buyingCommand->CoordinationY = 7;
	buyingCommand->Execute();
	buyingCommand->CoordinationX = 4;
	buyingCommand->CoordinationY = 4;
	buyingCommand->Execute();
	buyingCommand->~BuyingLandActionCommand();

	Player1->FindCardById(MOLE_CARD_ID)->Owned = 1;
	Player1->FindCardById(FERTILIZER_CARD_ID)->Owned = 2;
	Player1->FindCardById(WATER_CARD_ID)->Owned = 6;
	Player1->FindCardById(TESTPLANT_CARD_ID)->Owned = 1;
	Player2->FindCardById(TESTPLANT_CARD_ID)->Owned = 1;

	MoleCardActionCommand* mole = new MoleCardActionCommand();
	mole->Player = Player1;
	mole->CoordinationX = 7;
	mole->CoordinationY = 7;
	mole->Execute();
	mole->CoordinationX = 6;
	mole->CoordinationY = 6;
	mole->Execute();
	mole->CoordinationX = 6;
	mole->CoordinationY = 7;
	mole->Execute();
	mole->~MoleCardActionCommand();

	HarvestingActionCommand* harvestingCommand = new HarvestingActionCommand();
	harvestingCommand->Player = Player1;
	harvestingCommand->Execute();
	harvestingCommand->~HarvestingActionCommand();

	FertilizerCardActionCommand* fertilizerCommand = new FertilizerCardActionCommand();
	fertilizerCommand->Player = Player1;
	fertilizerCommand->CardID = FERTILIZER_CARD_ID;
	fertilizerCommand->Execute();
	fertilizerCommand->Execute();
	fertilizerCommand->Execute();
	fertilizerCommand->~FertilizerCardActionCommand();

	PlantingActionCommand* plantingCommand = new PlantingActionCommand();
	plantingCommand->Player = Player1;
	plantingCommand->CardID = TESTPLANT_CARD_ID;
	plantingCommand->CoordinationX = 0;
	plantingCommand->CoordinationY = 0;
	plantingCommand->Execute();
	plantingCommand->Execute();
	plantingCommand->Execute();
	plantingCommand->~PlantingActionCommand();

	PlantingActionCommand* plantingCommand2 = new PlantingActionCommand();
	plantingCommand2->Player = Player2;
	plantingCommand2->CardID = TESTPLANT_CARD_ID;
	plantingCommand2->CoordinationX = 6;
	plantingCommand2->CoordinationY = 7;
	plantingCommand2->Execute();
	plantingCommand2->~PlantingActionCommand();

	WateringActionCommand* wateringCommand = new WateringActionCommand();
	wateringCommand->Player = Player1;
	wateringCommand->CoordinationX = 0;
	wateringCommand->CoordinationY = 0;
	wateringCommand->Execute();
	wateringCommand->Execute();
	wateringCommand->Execute();
	wateringCommand->~WateringActionCommand();

}
*/
void AGameMap::Rain()
{
	//startAnimation();
	for (TArray<ATile*> tiles : Tiles)
	{
		for (ATile* tile : tiles)
		{
			if (tile->bIsPlanted)
			{
				tile->Plant->Water(1);
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
	}
}

void AGameMap::NextTurn()
{
	if (this->turn % RAIN_DAY == 0)
	{
		Rain();
	}
	RotPlants();
	DecrementFertilizers();
	turn++;
	//if (turn == 100) end game 
}