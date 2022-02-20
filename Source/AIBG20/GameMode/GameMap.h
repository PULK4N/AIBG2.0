// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../EntityDTO/TileDTO.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMap.generated.h"

class ATile;
class AGamePlayer;
class ASpawnService;
class AOutputService;

UENUM()
enum class EGameMode : uint8 {
	AI_VS_AI UMETA	(DisplayName = "AI_VS_AI"),
	AI_VS_GAME UMETA	(DisplayName = "AI_VS_GAME"),
	PLAYER_VS_GAME UMETA	(DisplayName = "PLAYER_VS_GAME"),
};
/**
 * 
 */
UCLASS()
class AIBG20_API AGameMap : public AGameModeBase
{
	GENERATED_BODY()
public:	
	AGameMap();
	~AGameMap();
	// Sets default values for this actor's properties

	TArray<TArray<ATile*>> Tiles;
	UPROPERTY(VisibleAnywhere, Category = "Players")
	AGamePlayer* Player1;
	UPROPERTY(VisibleAnywhere, Category = "Players")
	AGamePlayer* Player2;

	UPROPERTY(VisibleAnywhere)
	AGamePlayer* OnTheMovePlayer;

	UPROPERTY(EditAnywhere)
	EGameMode gamemode;//TODO: convert to GameModeBase, create blueprint foreach create different spawning
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpawnService> SpawnServiceToSpawn;

	UPROPERTY(EditAnywhere)
	int turn;
	AOutputService* outputService;

	UFUNCTION(BlueprintImplementableEvent)
	void ShowWinner();
	UFUNCTION(BlueprintImplementableEvent)
	void StartRainAnimation();
	UFUNCTION(BlueprintImplementableEvent)
	void ShowCards();
	UFUNCTION(BlueprintImplementableEvent)
	void TriggerEnemyAI();

public:	
	ATile* FindTile(int x, int y);
	int WhoOwnesTile(int x, int y);

	UFUNCTION(BlueprintCallable)
	int getNumOfTurns();
	UFUNCTION(BlueprintCallable)
	void SwitchPlayers();

	void NextTurn();
	void Rain();
	void DecrementFertilizers();
	void RotPlants();
	AGamePlayer* GetEnemyPlayer(AGamePlayer* source);
	TArray<FTileDTO> GenerateMinimalDTO();

};
