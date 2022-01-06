// Fill out your copyright notice in the Description page of Project Settings.


#include "AnemoneFlower.h"

AAnemoneFlower::AAnemoneFlower() {
	PrimaryActorTick.bCanEverTick = false;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	WaterNeeded = ANEMONE_FLOWER_WATER_NEEDED;
	DaysToRot = ANEMONE_FLOWER_DAYS_TO_ROT;
	GoldWorth = ANEMONE_FLOWER_GOLD_WORTH;
	DaysToRotCurrent = DaysToRot;
}