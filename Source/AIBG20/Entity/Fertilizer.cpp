// Fill out your copyright notice in the Description page of Project Settings.


#include "Fertilizer.h"
#include "../Defines.h"

// Sets default values
AFertilizer::AFertilizer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Id = FERTILIZER_CARD_ID;
	Owned = 0;
	Price = FERTILIZER_COST;
}

// Called when the game starts or when spawned
void AFertilizer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFertilizer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

