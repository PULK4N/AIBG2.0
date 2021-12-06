// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ActionCommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class AIBG20_API MoleCardActionCommand : public ActionCommand
{
public:
	MoleCardActionCommand();
	~MoleCardActionCommand();
	virtual void Execute() override;
protected:
	virtual bool CanExecute() override;
};
