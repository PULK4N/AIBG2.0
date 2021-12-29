// Fill out your copyright notice in the Description page of Project Settings.
#include "TimerService.h"
#include "Components/TextRenderComponent.h"
#include "../Defines.h"
ATimerService::ATimerService()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CountdownTime = TIME_TIL_NEXT_TURN;
}


void ATimerService::StartTimer(float sec)
{
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATimerService::AdvanceTimer, TIME_TIL_NEXT_TURN, true);
	this->bIsFinished = false;
}

void ATimerService::AdvanceTimer()
{
	this->bIsFinished = true;
}

// Called when the game starts or when spawned
void ATimerService::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATimerService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

