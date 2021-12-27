// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingActionCommand.h"

BuyingActionCommand::BuyingActionCommand()
{
}

BuyingActionCommand::~BuyingActionCommand()
{
}

BuyingActionCommand::BuyingActionCommand(int CardID, int amount) 
{
	this.CardID = CardID;
	this.amount = amount;
}

void BuyingActionCommand::Execute()
{
	if (CanExecute() == false)
		return;
//	Player->Cards.Add(Card);
	
}

bool BuyingActionCommand::CanExecute()
{
	int GoldLeft = Player->Gold - (Card->Price * AmountOfCards);
	return GoldLeft >= 0;
}
