// Fill out your copyright notice in the Description page of Project Settings.


#include "FertilizerCardActionCommand.h"
#include "../Entity/Fertilizer.h"
#include "../Entity/GameMap.h"

FertilizerCardActionCommand::FertilizerCardActionCommand()
{
}

FertilizerCardActionCommand::~FertilizerCardActionCommand()
{

}

FertilizerCardActionCommand::FertilizerCardActionCommand(AGamePlayer* Player)
{
	this->Player = Player;
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
	return Player->FindCardById(CardId)->Owned > 0;
}