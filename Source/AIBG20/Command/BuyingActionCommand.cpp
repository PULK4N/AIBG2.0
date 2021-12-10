// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingActionCommand.h"

BuyingActionCommand::BuyingActionCommand()
{
}

BuyingActionCommand::~BuyingActionCommand()
{
}

void BuyingActionCommand::Execute()
{
	if (CanExecute()) {
		Player->Gold -= (Card->Price * AmountOfCards);
		Player->BuyCard(Card->Id, AmountOfCards);
	}
	Card->Destroy();
}

bool BuyingActionCommand::CanExecute()
{
	int GoldLeft = Player->Gold - (Card->Price * AmountOfCards);
	return GoldLeft >= 0;
}
