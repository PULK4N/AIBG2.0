// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OutputService.generated.h"

class AGameMap;
class AGamePlayer;

UCLASS()
class AIBG20_API AOutputService : public AActor
{
	GENERATED_BODY()
public:	
	AOutputService();
	~AOutputService();
	void SendOutput(AGameMap* gm, AGamePlayer* gp);

};
