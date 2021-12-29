// Fill out your copyright notice in the Description page of Project Settings.


#include "Tulip.h"

ATulip::ATulip() {
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}