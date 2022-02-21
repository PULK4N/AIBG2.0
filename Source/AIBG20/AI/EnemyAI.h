// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyAI.generated.h"

class AGamePlayer;
class AGameMap;

UCLASS()
class AIBG20_API AEnemyAI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void ExecuteBotCommand();


public:	
	AGameMap* GameMap;
	AGamePlayer* SourceGamePlayer;
	AGamePlayer* EnemyPlayer;

//	UFUNCTION(BlueprintCallable)
};