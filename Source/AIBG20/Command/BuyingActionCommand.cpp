// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingActionCommand.h"
#include "..\Entity\Fertilizer.h"
#include "..\Entity\Mole.h"
#include "..\Entity\Water.h"
#include "..\Entity\Plant.h"

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
		Player->FindCardById(Card->Id)->Owned += AmountOfCards;
		delete Card;
	}

}

bool BuyingActionCommand::CanExecute()
{
	int GoldLeft = Player->Gold - (Card->Price * AmountOfCards);
	return GoldLeft >= 0;
}
