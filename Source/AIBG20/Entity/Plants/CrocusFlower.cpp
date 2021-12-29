// Fill out your copyright notice in the Description page of Project Settings.


#include "CrocusFlower.h"

ACrocusFlower::ACrocusFlower() {
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}