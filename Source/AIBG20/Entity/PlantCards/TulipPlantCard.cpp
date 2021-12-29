// Fill out your copyright notice in the Description page of Project Settings.


#include "TulipPlantCard.h"
#include "../../Defines.h"

ATulipPlantCard::ATulipPlantCard() {
	PrimaryActorTick.bCanEverTick = false;
	Id = TULIP_CARD_ID;
	Owned = 0;
	Price = TULIP_COST;
}

ATulipPlantCard::~ATulipPlantCard()
{
}
