// Fill out your copyright notice in the Description page of Project Settings.


#include "FertilizerCardActionCommand.h"
#include "../Entity/Fertilizer.h"
#include "../GameMode/GameMap.h"
#include "../Defines.h"

FertilizerCardActionCommand::FertilizerCardActionCommand()
{
}

FertilizerCardActionCommand::~FertilizerCardActionCommand()
{
	UE_LOG(LogTemp, Warning, TEXT("FertilizerCardActionCommand deleted"));
}

FertilizerCardActionCommand::FertilizerCardActionCommand(AGamePlayer* Player)
{
	this->Player = Player;
	this->CardId = FERTILIZER_CARD_ID;
}

void FertilizerCardActionCommand::Execute()
{
	if (CanExecute()) {
		Player->AddFertilizer();
        Player->FindCardById(CardId)->Owned--;
		UE_LOG(LogTemp, Warning, TEXT("Fertilizer action executed"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Fertilizer action couldn't execute because player doesn't own enough fertilizers"));
	}
}

bool FertilizerCardActionCommand::CanExecute()
{
	if (Player->FindCardById(CardId) == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Card does not exist"));
		return false;
	}
	return Player->FindCardById(CardId)->Owned > 0;
}