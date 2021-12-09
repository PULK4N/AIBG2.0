// Fill out your copyright notice in the Description page of Project Settings.


#include "FertilizerCardActionCommand.h"
#include "../Entity/Fertilizer.h"

FertilizerCardActionCommand::FertilizerCardActionCommand()
{
	Card = &AFertilizer();
}

FertilizerCardActionCommand::~FertilizerCardActionCommand()
{

}

void FertilizerCardActionCommand::Execute()
{
	if (CanExecute()) {
		Player->AddFertilizer();
        Player->FindCardById(Card->Id)->Owned--;
        delete Card;
	}
}

bool FertilizerCardActionCommand::CanExecute()
{
	return Player->FindCardById(Card->Id)->Owned > 0
}