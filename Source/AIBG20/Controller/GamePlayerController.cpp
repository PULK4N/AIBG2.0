// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayerController.h"


void AGamePlayerController::ExecuteAction(AGamePlayer* currentPlayer, ATile* currentTile, int cardId,EActions currentAction)
{
	if (currentAction == EActions::BUY_LAND)
	{
		BuyingLandActionCommand* buyCommand = new BuyingLandActionCommand(currentPlayer, currentTile->X, currentTile->Y, 1);
		buyCommand->Execute();
		delete buyCommand;
	}
	else if (currentAction == EActions::WATER)
	{
		WateringActionCommand* waterCommand = new WateringActionCommand(currentPlayer, currentTile->X, currentTile->Y, WATER_CARD_ID, 1);
		waterCommand->Execute();
		delete waterCommand;
	}
	else if (currentAction == EActions::FERTILIZER)
	{
		FertilizerCardActionCommand* fertilizerCommand = new FertilizerCardActionCommand(currentPlayer);
		fertilizerCommand->Execute();
		delete fertilizerCommand;
	}
	else if (currentAction == EActions::MOLE)
	{
		MoleCardActionCommand* moleCommand = new MoleCardActionCommand(currentPlayer, currentTile->X, currentTile->Y, MOLE_CARD_ID, 1);
		moleCommand->Execute();
		delete moleCommand;
	}
	else if (currentAction == EActions::PLANT)
	{
		PlantingActionCommand* plantingCommand = new PlantingActionCommand(cardId, currentTile->X, currentTile->Y, currentPlayer);
		plantingCommand->Execute();
		delete plantingCommand;
	}
	else if (currentAction == EActions::HARVEST)
	{
		HarvestingActionCommand* harvestCommand = new HarvestingActionCommand(currentPlayer);
		harvestCommand->Execute();
		delete harvestCommand;
	}
	else if (currentAction == EActions::SHOP)
	{
		BuyingActionCommand* shopCommand = new BuyingActionCommand(cardId, 1, currentPlayer);
		shopCommand->Execute();
		delete shopCommand;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Current command state is NONE!"));
	}
}
