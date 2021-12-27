// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlantCard.h"
#include "../../Defines.h"

ATestPlantCard::ATestPlantCard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Id = TESTPLANT_CARD_ID;
	Owned = 0;
	Price = 10000;
}

ATestPlantCard::~ATestPlantCard()
{
}

// Called when the game starts or when spawned
void ATestPlantCard::BeginPlay()
{
	Super::BeginPlay();

}