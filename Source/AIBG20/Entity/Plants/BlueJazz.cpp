// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueJazz.h"

ABlueJazz::ABlueJazz() {
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}