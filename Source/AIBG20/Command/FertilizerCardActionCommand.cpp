// Fill out your copyright notice in the Description page of Project Settings.


#include "FertilizerCardActionCommand.h"
#include "../Entity/Fertilizer.h"

FertilizerCardActionCommand::FertilizerCardActionCommand()
{
}

FertilizerCardActionCommand::~FertilizerCardActionCommand()
{

}

void FertilizerCardActionCommand::Execute()
{
	if (CanExecute() == false)
		return;
//	Player->Cards.Remove(GetFertilizerCard());
}

bool FertilizerCardActionCommand::CanExecute()
{
	//for (ACard* card : Player->Cards) {
	//	if (IsFertilizer(card)) {
	//		return true;
	//	}
	//}
	return false;
}

ACard* FertilizerCardActionCommand::GetFertilizerCard() {
	//for (ACard* card : Player->Cards) {
	//	if (IsFertilizer(card)) {
	//		return card;
	//	}
	//}
	return nullptr;
}

bool FertilizerCardActionCommand::IsFertilizer(ACard* card) {
	return dynamic_cast<AFertilizer*>(card) != nullptr;
}
