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
			GameMap = instance;
//		if (GameMap == nullptr)
	}
public:
	ActionCommand();
	~ActionCommand();

	AGamePlayer* Player;
	int CoordinationX;
	int CoordinationY;
	int CardId;
	int AmountOfCards;

	virtual void Execute();
protected:
	virtual bool CanExecute();

};
