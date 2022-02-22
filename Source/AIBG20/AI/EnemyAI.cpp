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

void AEnemyAI::ExecuteBotCommand()
{
	UE_LOG(LogTemp, Warning, TEXT("Bot has executed a command"));
	//your implementation here
	if (sequenceCounter == 0)
	{
		currentSequence = Evaluate();
	}
	int num_of_owned_tiles = SourceGamePlayer->Tiles.Num();
	int num_of_tiles_to_buy = sqrt(num_of_owned_tiles) * 2 + 1;
	if (currentSequence == BUYLAND_SHOP_PLANT_WATER_FERTILIZER_HARVEST)
	{
		if (sequenceCounter == 1)
		{
			
			for (int i = 7; i >= 7 - sqrt(num_of_owned_tiles); i--)
			{
				BuyingLandActionCommand* buyCommand = new BuyingLandActionCommand(SourceGamePlayer, 7-sqrt(num_of_owned_tiles), i, 1);
				buyCommand->Execute();
				delete buyCommand;
			}
			for (int i = 7; i >= 7 - sqrt(num_of_owned_tiles)+1; i--)
			{
				BuyingLandActionCommand* buyCommand = new BuyingLandActionCommand(SourceGamePlayer,i ,7 - sqrt(num_of_owned_tiles) , 1);
				buyCommand->Execute();
				delete buyCommand;
			}


			sequenceCounter=2;
			
		}
		else if (sequenceCounter == 2)
		{
			if (flowerToBuy == TULIP)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(TULIP_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles*TULIP_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
				BuyingActionCommand* fertilizerBuyingCommand = new BuyingActionCommand(FERTILIZER_CARD_ID, 2, SourceGamePlayer);
				fertilizerBuyingCommand->Execute();
				delete fertilizerBuyingCommand;
			}
			else if (flowerToBuy == CROCUS)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(CROCUS_FLOWER_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * CROCUS_FLOWER_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
				BuyingActionCommand* fertilizerBuyingCommand = new BuyingActionCommand(FERTILIZER_CARD_ID, 1, SourceGamePlayer);
				fertilizerBuyingCommand->Execute();
				delete fertilizerBuyingCommand;
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(BLUE_JAZZ_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * BLUE_JAZZ_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
				BuyingActionCommand* fertilizerBuyingCommand = new BuyingActionCommand(FERTILIZER_CARD_ID, 1, SourceGamePlayer);
				fertilizerBuyingCommand->Execute();
				delete fertilizerBuyingCommand;
			}
			else if (flowerToBuy == ANEMONE)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(ANEMONE_FLOWER_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * ANEMONE_FLOWER_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
				BuyingActionCommand* fertilizerBuyingCommand = new BuyingActionCommand(FERTILIZER_CARD_ID, 1, SourceGamePlayer);
				fertilizerBuyingCommand->Execute();
				delete fertilizerBuyingCommand;
			}


			sequenceCounter=3;
		}
		else if (sequenceCounter == 3)
		{
			if (flowerToBuy == TULIP)
			{
				FertilizerCardActionCommand* fertilizerCommand = new FertilizerCardActionCommand(SourceGamePlayer);
				fertilizerCommand->Execute();
				delete fertilizerCommand;
				FertilizerCardActionCommand* secondFertilizerCommand = new FertilizerCardActionCommand(SourceGamePlayer);
				secondFertilizerCommand->Execute();
				delete secondFertilizerCommand;
			}
			else if (flowerToBuy == CROCUS)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(CROCUS_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(BLUE_JAZZ_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}
			else if (flowerToBuy == ANEMONE)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(ANEMONE_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}

				sequenceCounter = 4;
		}
		else if (sequenceCounter == 4)
		{
			bool HoldMarker = false;
			if (flowerToBuy == TULIP)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					if (GameMap->getNumOfTurns() % 10 != 9)
					{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(TULIP_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
					}
					else
						HoldMarker = true;
				}
				
			}
			else if (flowerToBuy == CROCUS)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					if (GameMap->getNumOfTurns() % 10 == 9)
					{
						WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, CROCUS_FLOWER_WATER_NEEDED-RAIN_WATER_DROPS);
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
					if (GameMap->getNumOfTurns() % 10 == 9)
					{
						WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, BLUE_JAZZ_WATER_NEEDED-RAIN_WATER_DROPS);
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
					if (GameMap->getNumOfTurns() % 10 == 9)
					{
						WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, ANEMONE_FLOWER_WATER_NEEDED-RAIN_WATER_DROPS);
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

			if (!HoldMarker)
				sequenceCounter = 5;
			else
				sequenceCounter = 4;
		}
		else if (sequenceCounter == 5)
		{
			
			if (flowerToBuy == TULIP)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, TULIP_WATER_NEEDED);
					wateringCommand->Execute();
					delete wateringCommand;
				}
			}
			else
			{
				FertilizerCardActionCommand* fertilizerCommand = new FertilizerCardActionCommand(SourceGamePlayer);
				fertilizerCommand->Execute();
				delete fertilizerCommand;
			}
			sequenceCounter=6;
		}
		else if (sequenceCounter == 6)
		{
			HarvestingActionCommand* harvestCommand = new HarvestingActionCommand(SourceGamePlayer);
			harvestCommand->Execute();
			delete harvestCommand;
			sequenceCounter = 0;
		}
	}
	else if (currentSequence == BUYLAND_SHOP_PLANT_WATER_HARVEST)
	{
		if (sequenceCounter == 1)
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


			sequenceCounter=2;

		}
		else if (sequenceCounter == 2)
		{
			if (flowerToBuy == TULIP)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(TULIP_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * TULIP_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
			}
			else if (flowerToBuy == CROCUS)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(CROCUS_FLOWER_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * CROCUS_FLOWER_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(BLUE_JAZZ_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * BLUE_JAZZ_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
			}
			else if (flowerToBuy == ANEMONE)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(ANEMONE_FLOWER_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * ANEMONE_FLOWER_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
			}


			sequenceCounter=3;
		}
		else if (sequenceCounter == 3)
		{
			bool HoldMarker = false;
			if (flowerToBuy == TULIP)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					if (GameMap->getNumOfTurns() % 10 != 9)
					{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(TULIP_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
					}
					else
						HoldMarker = true;
				}
			}
			else if (flowerToBuy == CROCUS)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(CROCUS_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(BLUE_JAZZ_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}
			else if (flowerToBuy == ANEMONE)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(ANEMONE_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}

			if (!HoldMarker)
				sequenceCounter = 4;
			else
				sequenceCounter = 3;
		}
		else if (sequenceCounter == 4)
		{
			if (flowerToBuy == TULIP)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, TULIP_WATER_NEEDED);
					wateringCommand->Execute();
					delete wateringCommand;

				}
			}
			else if (flowerToBuy == CROCUS)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					if (GameMap->getNumOfTurns() % 10 == 9)
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
					if (GameMap->getNumOfTurns() % 10 == 9)
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
					if (GameMap->getNumOfTurns() % 10 == 9)
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


			sequenceCounter=5;
		}
		else if (sequenceCounter == 5)
		{
			HarvestingActionCommand* harvestCommand = new HarvestingActionCommand(SourceGamePlayer);
			harvestCommand->Execute();
			delete harvestCommand;
			sequenceCounter = 0;
		}
	}
	else if (currentSequence == SHOP_PLANT_WATER_FERTILIZER_HARVEST)
	{
		if (sequenceCounter == 1)
		{
			if (flowerToBuy == TULIP)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(TULIP_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * TULIP_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
				BuyingActionCommand* fertilizerBuyingCommand = new BuyingActionCommand(FERTILIZER_CARD_ID, 2, SourceGamePlayer);
				fertilizerBuyingCommand->Execute();
				delete fertilizerBuyingCommand;
			}
			else if (flowerToBuy == CROCUS)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(CROCUS_FLOWER_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * CROCUS_FLOWER_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
				BuyingActionCommand* fertilizerBuyingCommand = new BuyingActionCommand(FERTILIZER_CARD_ID, 1, SourceGamePlayer);
				fertilizerBuyingCommand->Execute();
				delete fertilizerBuyingCommand;
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(BLUE_JAZZ_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * BLUE_JAZZ_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
				BuyingActionCommand* fertilizerBuyingCommand = new BuyingActionCommand(FERTILIZER_CARD_ID, 1, SourceGamePlayer);
				fertilizerBuyingCommand->Execute();
				delete fertilizerBuyingCommand;
			}
			else if (flowerToBuy == ANEMONE)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(ANEMONE_FLOWER_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * ANEMONE_FLOWER_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
				BuyingActionCommand* fertilizerBuyingCommand = new BuyingActionCommand(FERTILIZER_CARD_ID, 1, SourceGamePlayer);
				fertilizerBuyingCommand->Execute();
				delete fertilizerBuyingCommand;
			}


			sequenceCounter=2;
		}
		else if (sequenceCounter == 2)
		{
			if (flowerToBuy == TULIP)
			{
				FertilizerCardActionCommand* fertilizerCommand = new FertilizerCardActionCommand(SourceGamePlayer);
				fertilizerCommand->Execute();
				delete fertilizerCommand;
				FertilizerCardActionCommand* secondFertilizerCommand = new FertilizerCardActionCommand(SourceGamePlayer);
				secondFertilizerCommand->Execute();
				delete secondFertilizerCommand;
			}
			else if (flowerToBuy == CROCUS)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(CROCUS_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(BLUE_JAZZ_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}
			else if (flowerToBuy == ANEMONE)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(ANEMONE_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}

			sequenceCounter = 3;
		}
		else if (sequenceCounter == 3)
		{
			bool HoldMarker = false;
			if (flowerToBuy == TULIP)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					if (GameMap->getNumOfTurns() != 9)
					{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(TULIP_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
					}
					else
						HoldMarker = true;
				}
				
			}
			else if (flowerToBuy == CROCUS)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					if (GameMap->getNumOfTurns() % 10 == 9)
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
					if (GameMap->getNumOfTurns() % 10 == 9)
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
					if (GameMap->getNumOfTurns() % 10 == 9)
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

			if (!HoldMarker)
				sequenceCounter = 4;
			else
				sequenceCounter = 3;
		}
		else if (sequenceCounter == 4)
		{
			
			if (flowerToBuy == TULIP)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, TULIP_WATER_NEEDED);
					wateringCommand->Execute();
					delete wateringCommand;
				}
			}
			else
			{
				FertilizerCardActionCommand* fertilizerCommand = new FertilizerCardActionCommand(SourceGamePlayer);
				fertilizerCommand->Execute();
				delete fertilizerCommand;
			}
			sequenceCounter=5;
		}
		else if (sequenceCounter == 5)
		{
			HarvestingActionCommand* harvestCommand = new HarvestingActionCommand(SourceGamePlayer);
			harvestCommand->Execute();
			delete harvestCommand;
			sequenceCounter = 0;
		}
	}
	else if (currentSequence == SHOP_PLANT_WATER_HARVEST)
	{
		if (sequenceCounter == 1)
		{
			if (flowerToBuy == TULIP)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(TULIP_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * TULIP_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
			}
			else if (flowerToBuy == CROCUS)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(CROCUS_FLOWER_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * CROCUS_FLOWER_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(BLUE_JAZZ_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * BLUE_JAZZ_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
			}
			else if (flowerToBuy == ANEMONE)
			{
				BuyingActionCommand* flowerCommand = new BuyingActionCommand(ANEMONE_FLOWER_CARD_ID, num_of_owned_tiles, SourceGamePlayer);
				flowerCommand->Execute();
				delete flowerCommand;
				BuyingActionCommand* waterBuyingCommand = new BuyingActionCommand(WATER_CARD_ID, num_of_owned_tiles * ANEMONE_FLOWER_WATER_NEEDED, SourceGamePlayer);
				waterBuyingCommand->Execute();
				delete waterBuyingCommand;
			}


			sequenceCounter=2;
		}
		else if (sequenceCounter == 2)
		{
			bool HoldMarker = false;
			if (flowerToBuy == TULIP)
			{
				for (int i = 0; i<num_of_owned_tiles; i++)
				{
					if (GameMap->getNumOfTurns() % 10 != 9)
					{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(TULIP_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
					}
					else
						HoldMarker = true;
				}
			}
			else if (flowerToBuy == CROCUS)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(CROCUS_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}
			else if (flowerToBuy == BLUE_JAZZ)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(BLUE_JAZZ_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}
			else if (flowerToBuy == ANEMONE)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
						PlantingActionCommand* plantingCommand = new PlantingActionCommand(ANEMONE_FLOWER_CARD_ID, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, SourceGamePlayer);
						plantingCommand->Execute();
						delete plantingCommand;
				}
			}

			if (!HoldMarker)
			{
				sequenceCounter = 3;
			}
			else
				sequenceCounter = 2;
			
		}
		else if (sequenceCounter == 3)
		{
			if (flowerToBuy == TULIP)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					WateringActionCommand* wateringCommand = new WateringActionCommand(SourceGamePlayer, SourceGamePlayer->Tiles[i]->X, SourceGamePlayer->Tiles[i]->Y, WATER_CARD_ID, TULIP_WATER_NEEDED);
					wateringCommand->Execute();
					delete wateringCommand;
				}
			}
			else if (flowerToBuy == CROCUS)
			{
				for (int i = 0; i < num_of_owned_tiles; i++)
				{
					if (GameMap->getNumOfTurns() % 10 == 9)
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
					if (GameMap->getNumOfTurns() % 10 == 9)
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
					if (GameMap->getNumOfTurns() % 10 == 9)
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


			sequenceCounter=4;
		}
		else if (sequenceCounter == 4)
		{
			HarvestingActionCommand* harvestCommand = new HarvestingActionCommand(SourceGamePlayer);
			harvestCommand->Execute();
			delete harvestCommand;
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
		return BUYLAND_SHOP_PLANT_WATER_FERTILIZER_HARVEST;
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
	else if ((2*FERTILIZER_COST + num_of_owned_tiles * (TULIP_COST + TULIP_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = TULIP;
		return SHOP_PLANT_WATER_FERTILIZER_HARVEST;
	}
	else if ((FERTILIZER_COST +  num_of_owned_tiles * (CROCUS_FLOWER_COST + CROCUS_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = CROCUS;
		return SHOP_PLANT_WATER_FERTILIZER_HARVEST;
	}
	else if ((FERTILIZER_COST + + num_of_owned_tiles * (BLUE_JAZZ_COST + BLUE_JAZZ_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = BLUE_JAZZ;
		return SHOP_PLANT_WATER_FERTILIZER_HARVEST;
	}
	else if ((FERTILIZER_COST+ num_of_owned_tiles * (ANEMONE_FLOWER_COST + ANEMONE_FLOWER_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter=1;
		flowerToBuy = ANEMONE;
		return SHOP_PLANT_WATER_FERTILIZER_HARVEST;
	}
	// kraj trece sekvence
	else if ((num_of_owned_tiles * (TULIP_COST + TULIP_WATER_NEEDED * WATER_COST)) < SourceGamePlayer->GetGold())
	{
		sequenceCounter = 1;
		flowerToBuy = TULIP;
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
	else
	{
		sequenceCounter = 0;
		return NONE;
	}

}



