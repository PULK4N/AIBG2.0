// Fill out your copyright notice in the Description page of Project Settings.


#include "CrocusFlowerPlantCard.h"

#include "../../Defines.h"

ACrocusFlowerPlantCard::ACrocusFlowerPlantCard() {
	PrimaryActorTick.bCanEverTick = false;
	Id = CROCUS_FLOWER_CARD_ID;
	Owned = 0;
	Price = CROCUS_FLOWER_COST;
}

ACrocusFlowerPlantCard::~ACrocusFlowerPlantCard()
{
}
