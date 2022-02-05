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

ATimerService::~ATimerService() {
	UE_LOG(LogTemp, Warning, TEXT("TimerService deleted"));
}


void ATimerService::StartTimer(float sec)
{
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATimerService::AdvanceTimer, sec, true);
}


void ATimerService::AdvanceTimer()
{
	//Animation is finished
	{//Maybe add mutex or FScopeLock
		this->bIsFinished = true;
		GameMap->SwitchPlayers();
	}
	GetWorldTimerManager().ClearAllTimersForObject(this);
	//allow player 'TIME_TIL_PLAYER_SWITCH' seconds to input something or switch players
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATimerService::TimerTriggerPlayerSwitch, TIME_TIL_PLAYER_SWITCH, true);
}

void ATimerService::TimerTriggerPlayerSwitch()
{
	if (GameMap->getNumOfTurns() > GAME_END_TURN) {
		return;
	}
	GameMap->SwitchPlayers();
	GetWorldTimerManager().ClearAllTimersForObject(this);
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATimerService::TimerTriggerPlayerSwitch, TIME_TIL_PLAYER_SWITCH, true);
}

// Called when the game starts or when spawned
void ATimerService::BeginPlay()
{
	Super::BeginPlay();
}

void ATimerService::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearAllTimersForObject(this);
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

void ATimerService::ClearTimers() {
	GetWorldTimerManager().ClearAllTimersForObject(this);
}