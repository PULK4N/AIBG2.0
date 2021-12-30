// Fill out your copyright notice in the Description page of Project Settings.


#include "Tulip.h"

ATulip::ATulip() {
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	WaterNeeded = TULIP_WATER_NEEDED;
	DaysToRot = TULIP_DAYS_TO_ROT;
	GoldWorth = TULIP_GOLD_WORTH;
}