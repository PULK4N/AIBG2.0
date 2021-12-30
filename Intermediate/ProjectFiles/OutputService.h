#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OutputService.generated.h"
#include <map>

class AGamePlayer;
class AGameMap;

UCLASS()
class AIBG20_API AOutputService : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOutputService();
	string convertToJSON(AGameMap* gm, AGamePlayer* gp);
	int** generateMap(AGameMap* gm);
	void setParams(AGameMap* gm, AGamePlayer* gp);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AGamePlayer* PlayerSource;
	// 0 - not owned by players
	// 1 - owned by Player1
	// 2 - owned by Player2
	int** TileMap;
	int fertilizerActive;
	bool bRainedThisTurn;
	int gold;
	int points;
	map<FString, int> cards;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};