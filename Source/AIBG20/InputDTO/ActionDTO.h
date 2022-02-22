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

};