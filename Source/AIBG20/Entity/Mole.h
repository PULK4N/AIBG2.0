// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mole.generated.h"
#include "Card.h"

UCLASS()
class AIBG20_API AMole : public ACard
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
