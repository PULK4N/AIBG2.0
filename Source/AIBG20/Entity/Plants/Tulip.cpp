// Fill out your copyright notice in the Description page of Project Settings.


#include "Tulip.h"

ATulip::ATulip() {
	PrimaryActorTick.bCanEverTick = false;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	Id = TULIP_CARD_ID;
	WaterNeeded = TULIP_WATER_NEEDED;
	DaysToRot = TULIP_DAYS_TO_ROT;
	GoldWorth = TULIP_GOLD_WORTH;
	DaysToRotCurrent = DaysToRot;
}