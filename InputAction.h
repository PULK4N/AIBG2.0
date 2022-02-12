// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputAction.generated.h"


USTRUCT()
struct FInputAction
{
	GENERATED_BODY()

	UPROPERTY()
	int X;
	UPROPERTY()
	int Y;
	UPROPERTY()
	int CardId;
	UPROPERTY()
	int Amount;

	FInputAction(int x = 0, int y = 0, int cardId = 0, int amount = 0) : X(x),Y(y), CardId(cardId), Amount(amount) {}

	//FDTO(FGamePlayerDTO source = FGamePlayerDTO(), FGamePlayerDTO enemy = FGamePlayerDTO(), int daysTillRain = 0) :
	//	Source(source), Enemy(enemy), DaysTillRain(daysTillRain) {}
};