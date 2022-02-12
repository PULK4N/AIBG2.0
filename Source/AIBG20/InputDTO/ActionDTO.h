// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActionPropertyDTO.h"
#include "ActionDTO.generated.h"

USTRUCT()
struct FActionDTO
{
	GENERATED_BODY()

	UPROPERTY()
	FString ActionType;

	UPROPERTY()
	TArray<FActionPropertyDTO> Properties;

	FActionDTO(FString actionType = "N") : ActionType(actionType) {}

	//FDTO(FGamePlayerDTO source = FGamePlayerDTO(), FGamePlayerDTO enemy = FGamePlayerDTO(), int daysTillRain = 0) :
	//	Source(source), Enemy(enemy), DaysTillRain(daysTillRain) {}
};