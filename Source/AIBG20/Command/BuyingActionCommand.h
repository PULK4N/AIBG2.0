// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActionCommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class AIBG20_API BuyingActionCommand : public ActionCommand
{
public:
	BuyingActionCommand();
	~BuyingActionCommand();
	BuyingActionCommand(int cardID, int amount, AGamePlayer* player);

	virtual void Execute() override;
protected:
	virtual bool CanExecute() override;
};
