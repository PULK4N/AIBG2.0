// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueJazz.h"

ABlueJazz::ABlueJazz() {
	PrimaryActorTick.bCanEverTick = false;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	Id = BLUE_JAZZ_CARD_ID;
	WaterNeeded = BLUE_JAZZ_WATER_NEEDED;
	DaysToRot = BLUE_JAZZ_DAYS_TO_ROT;
	GoldWorth = BLUE_JAZZ_GOLD_WORTH;
	DaysToRotCurrent = DaysToRot;
}