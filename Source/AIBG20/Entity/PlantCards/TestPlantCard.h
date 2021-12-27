// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../PlantCard.h"
#include "TestPlantCard.generated.h"

/**
 * 
 */
UCLASS()
class AIBG20_API ATestPlantCard : public APlantCard
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	ATestPlantCard();
	~ATestPlantCard();
};
