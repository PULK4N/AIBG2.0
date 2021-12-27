// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActionCommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class AIBG20_API BuyingLandActionCommand : public ActionCommand
{
public:
	BuyingLandActionCommand();
	~BuyingLandActionCommand();

	virtual void Execute() override;
protected:
	virtual bool CanExecute() override;
	bool TileAlreadyOwned();
	bool IsNeighbourTile();
	void BuyTile();
	void ChangeTileLookByOwner(ATile* tile);
};
