// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlant.h"

ATestPlant::ATestPlant() {
	PrimaryActorTick.bCanEverTick = false;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

ATestPlant::~ATestPlant() {

}