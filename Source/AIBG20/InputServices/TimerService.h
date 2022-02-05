// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerService.generated.h"

class AGameMap;

UCLASS()
class AIBG20_API ATimerService : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	~ATimerService();
	ATimerService();
	void SetGameMapInstance(AGameMap* gameMap);
	void ClearTimers();
	bool timing;
	void StartTimer(float sec);
	bool bIsFinished;
	void AdvanceTimer();
	void TimerTriggerPlayerSwitch();
	FTimerHandle CountdownTimerHandle;

protected:
	UPROPERTY()
	AGameMap* GameMap;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
