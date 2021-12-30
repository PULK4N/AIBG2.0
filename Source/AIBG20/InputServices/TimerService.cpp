// Fill out your copyright notice in the Description page of Project Settings.
#include "TimerService.h"
#include "Components/TextRenderComponent.h"
#include "../Defines.h"
#include "../Entity/GameMap.h"
ATimerService::ATimerService()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bIsFinished = true;
	GameMap = nullptr;
}


void ATimerService::StartTimer(float sec)
{
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATimerService::AdvanceTimer, sec, true);
	this->bIsFinished = false;
}


void ATimerService::AdvanceTimer()
{
	//Animation is finished
	this->bIsFinished = true;
	GetWorldTimerManager().ClearAllTimersForObject(this);
	//allow player 'TIME_TIL_PLAYER_SWITCH' seconds to input something or switch players
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATimerService::TimerTriggerPlayerSwitch, TIME_TIL_PLAYER_SWITCH, true);
}

void ATimerService::TimerTriggerPlayerSwitch()
{
	GameMap->SwitchPlayers();
	GetWorldTimerManager().ClearAllTimersForObject(this);
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATimerService::TimerTriggerPlayerSwitch, TIME_TIL_PLAYER_SWITCH, true);
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

void ATimerService::SetGameMapInstance(AGameMap* gameMap) {
	if(GameMap == nullptr)
		this->GameMap = gameMap;
}