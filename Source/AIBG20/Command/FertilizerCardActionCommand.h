// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ActionCommand.h"
#include "CoreMinimal.h"

/**
 * 
 */

class AIBG20_API FertilizerCardActionCommand : public ActionCommand
{
public:
	FertilizerCardActionCommand();
	~FertilizerCardActionCommand();

	FertilizerCardActionCommand(AGamePlayer* Player);

	virtual void Execute() override;
protected:
	virtual bool CanExecute() override;
};
