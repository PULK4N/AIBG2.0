// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActionCommand.h"
#include "CoreMinimal.h"
/**
 * 
 */
class AIBG20_API WateringActionCommand : public ActionCommand
{
public:
	WateringActionCommand();
	~WateringActionCommand();
	WateringActionCommand(AGamePlayer* Player, int CoordinationX, int CoordinationY, int CardID, int AmountOfCards);
	
	virtual void Execute() override;
protected:
	virtual bool CanExecute() override;
};
