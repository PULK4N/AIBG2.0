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

void FertilizerCardActionCommand::Execute()
{
	Card = GameMap->GetWorld()->SpawnActor<AFertilizer>(AFertilizer::StaticClass());
	if (CanExecute()) {
		Player->AddFertilizer();
        Player->FindCardById(Card->Id)->Owned--;
		UE_LOG(LogTemp, Warning, TEXT("Fertilizer action executed"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Fertilizer action couldn't execute because player doesn't own enough fertilizers"));
	}
    Card->Destroy();
}

bool FertilizerCardActionCommand::CanExecute()
{
	return Player->FindCardById(Card->Id)->Owned > 0;
}