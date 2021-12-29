// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueJazzPlantCard.h"

#include "../../Defines.h"

ABlueJazzPlantCard::ABlueJazzPlantCard() {
	PrimaryActorTick.bCanEverTick = false;
	Id = BLUE_JAZZ_CARD_ID;
	Owned = 0;
	Price = BLUE_JAZZ_COST;
}

ABlueJazzPlantCard::~ABlueJazzPlantCard()
{
}
