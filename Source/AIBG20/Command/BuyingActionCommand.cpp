// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingActionCommand.h"

BuyingActionCommand::BuyingActionCommand()
{
}

BuyingActionCommand::~BuyingActionCommand()
{
	UE_LOG(LogTemp, Warning, TEXT("BuyingActionCommand deleted"));
}

BuyingActionCommand::BuyingActionCommand(int CardId, int amount, AGamePlayer* player)
{
	this->Player = player;
	this->CardId = CardId;
	this->Amount = amount;
}

void BuyingActionCommand::Execute()
{
	ACard* Card = Player->FindCardById(CardId);
	if (CanExecute()) {
		Player->Gold -= (Card->Price * Amount);
		Player->BuyCard(Card->Id, Amount);
		UE_LOG(LogTemp, Warning, TEXT("Buying action action executed"));
	}
}

bool BuyingActionCommand::CanExecute()
{
	if (Player->FindCardById(CardId) == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Card does not exist"));
		return false;
	}

	ACard* Card = Player->FindCardById(CardId);
	if (Player->Gold - (Card->Price * Amount) < 0) {
		UE_LOG(LogTemp, Warning, TEXT("Buying action couldn't execute because player doesn't have enough money"));
		return false;
	}
	return true;
}
