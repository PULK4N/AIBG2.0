// Fill out your copyright notice in the Description page of Project Settings.


#include "AnemoneFlowerPlantCard.h"
#include "../../Defines.h"

AAnemoneFlowerPlantCard::AAnemoneFlowerPlantCard() {
	PrimaryActorTick.bCanEverTick = false;
	Id = ANEMONE_FLOWER_CARD_ID;
	Owned = 0;
	Price = ANEMONE_FLOWER_COST;
}

AAnemoneFlowerPlantCard::~AAnemoneFlowerPlantCard()
{
}
