// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Entity/Card.h"
#include "../Entity/GamePlayer.h"

class AGameMap;
/**
 * 
 */
class AIBG20_API ActionCommand
{
protected:
	static AGameMap* GameMap;
public:
	static void SetGameMapInstance(AGameMap* instance) {
		if (GameMap == nullptr)
			GameMap = instance;
	}
public:
	ActionCommand();
	~ActionCommand();

	AGamePlayer* Player;
	int CoordinationX;
	int CoordinationY;
	ACard* Card;
	int AmountOfCards;

	virtual void Execute();
protected:
	virtual bool CanExecute();

};
