// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingActionCommand.h"

BuyingActionCommand::BuyingActionCommand()
{
}

BuyingActionCommand::~BuyingActionCommand()
{
}

BuyingActionCommand::BuyingActionCommand(int CardID, int amount, AGamePlayer* player) 
{
	this->Player = player;
	this->CardID = CardID;
	this->AmountOfCards = amount;
}

void BuyingActionCommand::Execute()
{
	ACard* Card = Player->FindCardById(CardID);
	if (CanExecute()) {
		Player->Gold -= (Card->Price * AmountOfCards);
		Player->BuyCard(Card->Id, AmountOfCards);
		UE_LOG(LogTemp, Warning, TEXT("Buying action action executed"));
	}
}

bool BuyingActionCommand::CanExecute()
{
	ACard* Card = Player->FindCardById(CardID);
	if (Player->Gold - (Card->Price * AmountOfCards) < 0) {
		UE_LOG(LogTemp, Warning, TEXT("Buying action couldn't execute because player doesn't have enough money"));
		return false;
	}
	return true;
}
