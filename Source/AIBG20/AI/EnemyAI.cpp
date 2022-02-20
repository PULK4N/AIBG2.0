// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"

#include "../GameMode/GameMap.h"
#include "../Entity/GamePlayer.h"

// Called when the game starts or when spawned
void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
	
}

AEnemyAI::AEnemyAI() {

}

void AEnemyAI::ExecuteBotCommand()
{
	UE_LOG(LogTemp, Warning, TEXT("Bot has executed a command"));
	//your implementation here
}



