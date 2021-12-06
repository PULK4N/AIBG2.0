// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ActionCommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class AIBG20_API PlantingActionCommand : public ActionCommand
{
public:
	PlantingActionCommand();
	~PlantingActionCommand();
	virtual void Execute() override;
protected:
	virtual bool CanExecute() override;
};
