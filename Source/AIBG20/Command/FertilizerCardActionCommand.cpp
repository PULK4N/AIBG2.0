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
	FActorSpawnParameters Spawnparams;
	AFertilizer fertilizer;
	Card = GameMap->GetWorld()->SpawnActor<AFertilizer>(fertilizer.GetClass(), Spawnparams);
	if (CanExecute()) {
		Player->AddFertilizer();
        Player->FindCardById(Card->Id)->Owned--;
	}
    Card->Destroy();
}

bool FertilizerCardActionCommand::CanExecute()
{
	return Player->FindCardById(Card->Id)->Owned > 0;
}