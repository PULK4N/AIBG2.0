// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActionCommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class AIBG20_API HarvestingActionCommand : public ActionCommand
{
public:
	HarvestingActionCommand();
	~HarvestingActionCommand();

	virtual void Execute() override;
protected:
	virtual bool CanExecute() override;
};
