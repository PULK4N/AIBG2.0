// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../EntityDTO/CardDTO.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

UCLASS()
class AIBG20_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();
	UPROPERTY(EditAnywhere)
	int Id;
	UPROPERTY(EditAnywhere)
	int Price;
	UPROPERTY(EditAnywhere)
	int Owned;

	FCardDTO GenerateDTO();

	UFUNCTION(BlueprintPure, Category = "Price")
	int GetPrice();
	UFUNCTION(BlueprintPure, Category = "Owned")
	int GetOwned();

};
