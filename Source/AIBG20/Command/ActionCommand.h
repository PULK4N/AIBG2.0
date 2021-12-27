// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Entity/Card.h"
#include "../Entity/GamePlayer.h"

/**
 * 
 */
class AIBG20_API ActionCommand
{
public:
	ActionCommand();
	~ActionCommand();

	AGamePlayer* Player;
	int CoordinationX;
	int CoordinationY;
	ACard* Card;
	int CardID;
	int AmountOfCards;

	virtual void Execute();
protected:
	virtual bool CanExecute();

};
