// Fill out your copyright notice in the Description page of Project Settings.


#include "AnemoneFlower.h"

AAnemoneFlower::AAnemoneFlower() {
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}