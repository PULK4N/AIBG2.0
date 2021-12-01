// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Card.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Water.generated.h"

UCLASS()
class AIBG20_API AWater : public ACard
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWater();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};