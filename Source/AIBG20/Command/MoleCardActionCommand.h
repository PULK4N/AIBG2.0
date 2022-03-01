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
	MoleCardActionCommand(AGamePlayer* Player, int CoordinationX, int CoordinationY, int CardId, int AmountOfCards);
	virtual void Execute() override;
protected:
	virtual bool CanExecute() override;
	bool EnemyOwnsTheTile(AGamePlayer* enemy, ATile* tile);
	void DestroyPlantIfPlanted(ATile* tile);
	void RemoveTileFromEnemy(ATile* tile);
	void AddTileToPlayer(ATile* tile);
};
