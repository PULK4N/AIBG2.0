// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"

#include "../GameMode/GameMap.h"
#include "../Entity/GamePlayer.h"
#include <math.h>

// Called when the game starts or when spawned
void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
}

AEnemyAI::AEnemyAI() {
	AEnemyAI::sequenceCounter = 0;
	AEnemyAI::currentSequence = NONE;
}

void AEnemyAI::BuyLand(int num_of_owned_tiles)
{
	for (int i = 7; i >= 7 - sqrt(num_of_owned_tiles); i--)
	{
		BuyingLandActionCommand* buyCommand = new BuyingLandActionCommand(SourceGamePlayer, 7 - sqrt(num_of_owned_tiles), i, 1);
		buyCommand->Execute();
		delete buyCommand;
	}
	for (int i = 7; i >= 7 - sqrt(num_of_owned_tiles) + 1; i--)
	{
		BuyingLandActionCommand* buyCommand = new BuyingLandActionCommand(SourceGamePlayer, i, 7 - sqrt(num_of_owned_tiles), 1);
		buyCommand->Execute();
		delete buyCommand;
	}
}

void AEnemyAI::BuyCard(int cardId, int amount)
{
	BuyingActionCommand* flowerCommand = new BuyingActionCommand(cardId, amount, SourceGamePlayer);
	flowerCommand->Execute();
	delete flowerCommand;
}

void AEnemyAI::PlaceFlowers(flower fl, int num_of_owned_tiles)
{
	if (fl == TULIP)
	{
		for (int i = 0; i < num_of_owned_tiles; i++)
		{
			PlantingActionCommand* plantingCommand = new PlantingActionCommand(TULIP_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
			plantingCommand->Execute();
			delete plantingCommand;
		}
	}
	else if (fl == CROCUS)
	{
		for (int i = 0; i < num_of_owned_tiles; i++)
		{
			PlantingActionCommand* plantingCommand = new PlantingActionCommand(CROCUS_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
			plantingCommand->Execute();
			delete plantingCommand;
		}
	}
	else if (fl == BLUE_JAZZ)
	{
		for (int i = 0; i < num_of_owned_tiles; i++)
		{
			PlantingActionCommand* plantingCommand = new PlantingActionCommand(BLUE_JAZZ_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
			plantingCommand->Execute();
			delete plantingCommand;
		}
	}
	else if (fl == ANEMONE)
	{
		for (int i = 0; i < num_of_owned_tiles; i++)
		{
			PlantingActionCommand* plantingCommand = new PlantingActionCommand(ANEMONE_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
			plantingCommand->Execute();
			delete plantingCommand;
		}
	}
}

void AEnemyAI::WaterFlowers(flower fl, int num_of_owned_tiles, bool Fertilizer)
{
	bool Rain;
	if (Fertilizer) {
		Rain = GameMap->getNumOfTurns() % 10 == 8 || GameMap->getNumOfTurns() % 10 == 9 || GameMap->getNumOfTurns() % 10 == 0;
	}
	else {
		Rain = GameMap->getNumOfTurns() % 10 == 9 || GameMap->getNumOfTurns() % 10 == 0;
	}
	if (flowerToBuy == TULIP)
	{
		for (int i = 0; i < num_of_owned_tiles; i++)
		{
			WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, TULIP_WATER_NEEDED);
			wateringCommand->Execute();
			delete wateringCommand;
		}
	}
	if (flowerToBuy == CROCUS)
	{
		for (int i = 0; i < num_of_owned_tiles; i++)
		{
			if (Rain)
			{
				WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, CROCUS_FLOWER_WATER_NEEDED - RAIN_WATER_DROPS);
				wateringCommand->Execute();
				delete wateringCommand;
			}
			else
			{
				WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, CROCUS_FLOWER_WATER_NEEDED);
				wateringCommand->Execute();
				delete wateringCommand;
			}
		}
	}
	else if (flowerToBuy == BLUE_JAZZ)
	{
		for (int i = 0; i < num_of_owned_tiles; i++)
		{
			if (Rain)
			{
				WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, BLUE_JAZZ_WATER_NEEDED - RAIN_WATER_DROPS);
				wateringCommand->Execute();
				delete wateringCommand;
			}
			else
			{
				WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, BLUE_JAZZ_WATER_NEEDED);
				wateringCommand->Execute();
				delete wateringCommand;
			}
		}
	}
	else if (flowerToBuy == ANEMONE)
	{
		for (int i = 0; i < num_of_owned_tiles; i++)
		{
			if (Rain)
			{
				WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, ANEMONE_FLOWER_WATER_NEEDED - RAIN_WATER_DROPS);
				wateringCommand->Execute();
				delete wateringCommand;
			}
			else
			{
				WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, ANEMONE_FLOWER_WATER_NEEDED);
				wateringCommand->Execute();
				delete wateringCommand;
			}
		}
	}
}

void AEnemyAI::ActivateFertilizer()
{
	FertilizerCardActionCommand* fertilizerCommand = new FertilizerCardActionCommand(SourceGamePlayer);
	fertilizerCommand->Execute();
	delete fertilizerCommand;
}

void AEnemyAI::HarvestFlowers()
{
	HarvestingActionCommand* harvestCommand = new HarvestingActionCommand(SourceGamePlayer);
	harvestCommand->Execute();
	delete harvestCommand;
}

void AEnemyAI::ExecuteBotCommand()
{
	UE_LOG(LogTemp, Warning, TEXT("--------------------------"));
	UE_LOG(LogTemp, Warning, TEXT("Bot has executed a command"));
	//your implementation here
	if (sequenceCounter == 0)
	{
		currentSequence = Evaluate();
	}
	int num_of_owned_tiles = SourceGamePlayer->Tiles.Num();
	int num_of_tiles_to_buy = sqrt(num_of_owned_tiles) * 2 + 1;
	if (currentSequence == BUYLAND_SHOP_FERTILIZER_FERTILIZER_PLANT_WATER_HARVEST) {
		if (sequenceCounter == 1)
		{
			BuyLand(num_of_owned_tiles);

			sequenceCounter = 2;

		}
		else if (sequenceCounter == 2)
		{
			BuyCard(TULIP_CARD_ID, num_of_owned_tiles);
			BuyCard(WATER_CARD_ID, num_of_owned_tiles* TULIP_WATER_NEEDED);
			BuyCard(FERTILIZER_CARD_ID, 2);
			sequenceCounter = 3;
		}
		else if (sequenceCounter == 3)
		{
			ActivateFertilizer();

			sequenceCounter = 4;
		}
		else if (sequenceCounter == 4)
		{
			ActivateFertilizer();
			sequenceCounter = 5;
		}
		else if (sequenceCounter == 5)
		{
			bool HoldMarker = (GameMap->getNumOfTurns() % RAIN_DAY) == 8 || (GameMap->getNumOfTurns() % RAIN_DAY) == 9;

			if (!HoldMarker) {
				PlaceFlowers(flowerToBuy, num_of_owned_tiles);
				sequenceCounter = 6;
			}
			else
				sequenceCounter = 5;
			
		}
		else if (sequenceCounter == 6)
		{
			WaterFlowers(flowerToBuy,num_of_owned_tiles,false);
			sequenceCounter = 7;
		}
		else if (sequenceCounter == 7) {
			HarvestFlowers();
			sequenceCounter = 0;
		}
	}
	else if (currentSequence == BUYLAND_SHOP_PLANT_WATER_FERTILIZER_HARVEST)
	{
		if (sequenceCounter == 1)
		{
			BuyLand(num_of_owned_tiles);
			sequenceCounter=2;
			
		}
		else if (sequenceCounter == 2)
		{
			if (flowerToBuy == CROCUS)
			{
				BuyCard(CROCUS_FLOWER_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles * CROCUS_FLOWER_WATER_NEEDED);
				BuyCard(FERTILIZER_CARD_ID, 1);
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				BuyCard(BLUE_JAZZ_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles * BLUE_JAZZ_WATER_NEEDED);
				BuyCard(FERTILIZER_CARD_ID, 1);
			}
			else if (flowerToBuy == ANEMONE)
			{
				BuyCard(ANEMONE_FLOWER_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles* ANEMONE_FLOWER_WATER_NEEDED);
				BuyCard(FERTILIZER_CARD_ID, 1);
			}


			sequenceCounter=3;
		}
		else if (sequenceCounter == 3)
		{
			PlaceFlowers(flowerToBuy, num_of_owned_tiles);

			sequenceCounter = 4;
		}
		else if (sequenceCounter == 4)
		{
			WaterFlowers(flowerToBuy, num_of_owned_tiles, true);
			sequenceCounter = 5;
		}
		else if (sequenceCounter == 5)
		{
			ActivateFertilizer();
			sequenceCounter=6;
		}
		else if (sequenceCounter == 6)
		{
			HarvestFlowers();
			sequenceCounter = 0;
		}
	}
	else if (currentSequence == BUYLAND_SHOP_PLANT_WATER_HARVEST)
	{
		if (sequenceCounter == 1)
		{

			BuyLand(num_of_owned_tiles);
			sequenceCounter=2;
		}
		else if (sequenceCounter == 2)
		{
			if (flowerToBuy == TULIP)
			{
				BuyCard(TULIP_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles* TULIP_WATER_NEEDED);
			}
			else if (flowerToBuy == CROCUS)
			{
				BuyCard(CROCUS_FLOWER_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles* CROCUS_FLOWER_WATER_NEEDED);
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				BuyCard(BLUE_JAZZ_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles* BLUE_JAZZ_WATER_NEEDED);
			}
			else if (flowerToBuy == ANEMONE)
			{
				BuyCard(ANEMONE_FLOWER_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles* ANEMONE_FLOWER_WATER_NEEDED);
			}

			sequenceCounter=3;
		}
		else if (sequenceCounter == 3)
		{
			bool HoldMarker = (GameMap->getNumOfTurns() % RAIN_DAY) == 8 || (GameMap->getNumOfTurns() % RAIN_DAY) == 9;
			if (flowerToBuy == TULIP && HoldMarker) {
				sequenceCounter = 3;
			}
			else {
				PlaceFlowers(flowerToBuy, num_of_owned_tiles);
				sequenceCounter = 4;
			}
		}
		else if (sequenceCounter == 4)
		{
			WaterFlowers(flowerToBuy, num_of_owned_tiles, false);

			sequenceCounter=5;
		}
		else if (sequenceCounter == 5)
		{
			HarvestFlowers();
			sequenceCounter = 0;
		}
	}
	else if (currentSequence == SHOP_FERTILIZER_FERTILIZER_PLANT_WATER_HARVEST) {
		if (sequenceCounter == 1)
		{
			BuyCard(TULIP_CARD_ID, num_of_owned_tiles);
			BuyCard(WATER_CARD_ID, num_of_owned_tiles* TULIP_WATER_NEEDED);
			BuyCard(FERTILIZER_CARD_ID, 1);

			sequenceCounter = 2;
		}
		else if (sequenceCounter == 2)
		{
			ActivateFertilizer();

			sequenceCounter = 3;
		}
		else if (sequenceCounter == 3)
		{
			ActivateFertilizer();
			sequenceCounter = 4;
		}
		else if (sequenceCounter == 4)
		{
			bool HoldMarker = GameMap->getNumOfTurns() % 10 == 8 || GameMap->getNumOfTurns() % 10 == 9;
			if (HoldMarker)
			{
				sequenceCounter = 4;
			}
			else {
				PlaceFlowers(flowerToBuy, num_of_owned_tiles);
				sequenceCounter = 5;
			}

		}
		else if (sequenceCounter == 5)
		{
			WaterFlowers(flowerToBuy, num_of_owned_tiles, false);

			sequenceCounter = 6;
		}
		else if (sequenceCounter == 6) {
			HarvestFlowers();
			sequenceCounter = 0;
		}
	}
	else if (currentSequence == SHOP_PLANT_WATER_FERTILIZER_HARVEST)
	{
		if (sequenceCounter == 1)
		{
			if (flowerToBuy == CROCUS)
			{
				BuyCard(CROCUS_FLOWER_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles * CROCUS_FLOWER_WATER_NEEDED);
				BuyCard(FERTILIZER_CARD_ID, 1);
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				BuyCard(BLUE_JAZZ_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles* BLUE_JAZZ_WATER_NEEDED);
				BuyCard(FERTILIZER_CARD_ID, 1);
			}
			else if (flowerToBuy == ANEMONE)
			{
				BuyCard(ANEMONE_FLOWER_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles* ANEMONE_FLOWER_WATER_NEEDED);
				BuyCard(FERTILIZER_CARD_ID, 1);
			}

			sequenceCounter=2;
		}
		else if (sequenceCounter == 2)
		{
			PlaceFlowers(flowerToBuy, num_of_owned_tiles);
			sequenceCounter = 3;
		}
		else if (sequenceCounter == 3)
		{
			WaterFlowers(flowerToBuy, num_of_owned_tiles,true);
			sequenceCounter = 4;
		}
		else if (sequenceCounter == 4)
		{
			ActivateFertilizer();
			sequenceCounter=5;
		}
		else if (sequenceCounter == 5)
		{
			HarvestFlowers();
			sequenceCounter = 0;
		}
	}
	else if (currentSequence == SHOP_PLANT_WATER_HARVEST)
	{
		if (sequenceCounter == 1)
		{
			if (flowerToBuy == TULIP)
			{
				BuyCard(TULIP_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles * TULIP_WATER_NEEDED);
			}
			else if (flowerToBuy == CROCUS)
			{
				BuyCard(CROCUS_FLOWER_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles * CROCUS_FLOWER_WATER_NEEDED);
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				BuyCard(BLUE_JAZZ_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles * BLUE_JAZZ_WATER_NEEDED);
			}
			else if (flowerToBuy == ANEMONE)
			{
				BuyCard(ANEMONE_FLOWER_CARD_ID, num_of_owned_tiles);
				BuyCard(WATER_CARD_ID, num_of_owned_tiles * ANEMONE_FLOWER_WATER_NEEDED);
			}
			sequenceCounter=2;
		}
		else if (sequenceCounter == 2)
		{
			bool HoldMarker = (GameMap->getNumOfTurns() % 10 == 8 || GameMap->getNumOfTurns() % 10 == 9) && flowerToBuy == TULIP;
			if (HoldMarker)
			{
				sequenceCounter = 2;
			}
			else {
				PlaceFlowers(flowerToBuy, num_of_owned_tiles);
				sequenceCounter = 3;
			}
		}
		else if (sequenceCounter == 3)
		{
			WaterFlowers(flowerToBuy, num_of_owned_tiles, false);
			sequenceCounter=4;
		}
		else if (sequenceCounter == 4)
		{
			HarvestFlowers();
			sequenceCounter = 0;
		}
	}

}

sequence AEnemyAI::Evaluate()
{
	int num_of_owned_tiles = SourceGamePlayer->Tiles.Num();
	int num_of_tiles_to_buy =int(sqrt(num_of_owned_tiles)) * 2 + 1;
	
	if ((num_of_tiles_to_buy * TILE_COST + 2*FERTILIZER_COST +(num_of_owned_tiles+num_of_tiles_to_buy) * (TULIP_COST + TULIP_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
		{
			sequenceCounter=1;
			flowerToBuy = TULIP;
			//if (IsGoingToRainOnTulip(BUYLAND_SHOP_FERTILIZER_FERTILIZER_PLANT_WATER_HARVEST)) {
			//	sequenceCounter = 0;
			//	return NONE;
			//}
			return BUYLAND_SHOP_FERTILIZER_FERTILIZER_PLANT_WATER_HARVEST;
		}
	else if ((num_of_tiles_to_buy * TILE_COST + FERTILIZER_COST + (num_of_owned_tiles + num_of_tiles_to_buy) * (CROCUS_FLOWER_COST + CROCUS_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
		{
			sequenceCounter=1;
			flowerToBuy = CROCUS;
			return BUYLAND_SHOP_PLANT_WATER_FERTILIZER_HARVEST;
		}
	else if ((num_of_tiles_to_buy * TILE_COST + FERTILIZER_COST + (num_of_owned_tiles + num_of_tiles_to_buy) * (BLUE_JAZZ_COST + BLUE_JAZZ_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
		{
			sequenceCounter=1;
			flowerToBuy = BLUE_JAZZ;
			return BUYLAND_SHOP_PLANT_WATER_FERTILIZER_HARVEST;
		}
	else if ((num_of_tiles_to_buy * TILE_COST + FERTILIZER_COST + (num_of_owned_tiles + num_of_tiles_to_buy) * (ANEMONE_FLOWER_COST + ANEMONE_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
		{
			sequenceCounter=1;
			flowerToBuy = ANEMONE;
			return BUYLAND_SHOP_PLANT_WATER_FERTILIZER_HARVEST;
		}

	//kraj najkompleksnije sekvence
	else if ((num_of_tiles_to_buy * TILE_COST + (num_of_owned_tiles + num_of_tiles_to_buy) * (TULIP_COST + TULIP_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = TULIP;
		return BUYLAND_SHOP_PLANT_WATER_HARVEST;
	}
	else if ((num_of_tiles_to_buy * TILE_COST + (num_of_owned_tiles + num_of_tiles_to_buy) * (CROCUS_FLOWER_COST + CROCUS_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = CROCUS;
		return BUYLAND_SHOP_PLANT_WATER_HARVEST;
	}
	else if ((num_of_tiles_to_buy * TILE_COST + (num_of_owned_tiles + num_of_tiles_to_buy) * (BLUE_JAZZ_COST + BLUE_JAZZ_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = BLUE_JAZZ;
		return BUYLAND_SHOP_PLANT_WATER_HARVEST;
	}
	else if ((num_of_tiles_to_buy * TILE_COST + (num_of_owned_tiles + num_of_tiles_to_buy) * (ANEMONE_FLOWER_COST + ANEMONE_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = ANEMONE;
		return BUYLAND_SHOP_PLANT_WATER_HARVEST;
	}
	// kraj druge najkompleksnije sekvence
	else if (SourceGamePlayer->Tiles.Num() > 4) {
		if ((2 * FERTILIZER_COST + num_of_owned_tiles * (TULIP_COST + TULIP_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter = 1;
		flowerToBuy = TULIP;
		//if (IsGoingToRainOnTulip(SHOP_FERTILIZER_FERTILIZER_PLANT_WATER_HARVEST)) {
		//	sequenceCounter = 0;
		//	return NONE;
		//}
		return SHOP_FERTILIZER_FERTILIZER_PLANT_WATER_HARVEST;
	}
		else if ((FERTILIZER_COST + num_of_owned_tiles * (CROCUS_FLOWER_COST + CROCUS_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter = 1;
		flowerToBuy = CROCUS;
		return SHOP_PLANT_WATER_FERTILIZER_HARVEST;
	}
		else if ((FERTILIZER_COST + +num_of_owned_tiles * (BLUE_JAZZ_COST + BLUE_JAZZ_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter = 1;
		flowerToBuy = BLUE_JAZZ;
		return SHOP_PLANT_WATER_FERTILIZER_HARVEST;
	}
		else if ((FERTILIZER_COST + num_of_owned_tiles * (ANEMONE_FLOWER_COST + ANEMONE_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter = 1;
		flowerToBuy = ANEMONE;
		return SHOP_PLANT_WATER_FERTILIZER_HARVEST;
	}
	}// kraj trece sekvence
	else if ((num_of_owned_tiles * (TULIP_COST + TULIP_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter = 1;
		flowerToBuy = TULIP;
		//if (IsGoingToRainOnTulip(SHOP_PLANT_WATER_HARVEST)) {
		//	sequenceCounter = 0;
		//	return NONE;
		//}
		return SHOP_PLANT_WATER_HARVEST;
	}
	else if ((num_of_owned_tiles * (CROCUS_FLOWER_COST + CROCUS_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = CROCUS;
		return SHOP_PLANT_WATER_HARVEST;
	}
	else if ((num_of_owned_tiles * (BLUE_JAZZ_COST + BLUE_JAZZ_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = BLUE_JAZZ;
		return SHOP_PLANT_WATER_HARVEST;
	}
	else if ((num_of_owned_tiles * (ANEMONE_FLOWER_COST + ANEMONE_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = ANEMONE;
		return SHOP_PLANT_WATER_HARVEST;
	}

	sequenceCounter = 0;
	return NONE;
}