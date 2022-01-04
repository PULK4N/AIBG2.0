// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GamePlayerDTO.h"
#include "DTO.generated.h"

/**
 * 
 */
USTRUCT()
struct FDTO
{
	GENERATED_BODY()

	UPROPERTY()
	FGamePlayerDTO Source;

	UPROPERTY()
	FGamePlayerDTO Enemy;

	UPROPERTY()
	int DaysTillRain;

	FDTO(FGamePlayerDTO source = FGamePlayerDTO(), FGamePlayerDTO enemy = FGamePlayerDTO(), int daysTillRain = 0) :
		Source(source), Enemy(enemy), DaysTillRain(daysTillRain){};
};
