// Fill out your copyright notice in the Description page of Project Settings.


#include "CrocusFlower.h"

ACrocusFlower::ACrocusFlower() {
	PrimaryActorTick.bCanEverTick = false;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	WaterNeeded = CROCUS_FLOWER_WATER_NEEDED;
	DaysToRot = CROCUS_FLOWER_DAYS_TO_ROT;
	GoldWorth = CROCUS_FLOWER_GOLD_WORTH;
	DaysToRotCurrent = DaysToRot;
}