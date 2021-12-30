// Fill out your copyright notice in the Description page of Project Settings.

#include "OutputService.h"
#include "Json.h"
#include <map>


int** AOutputService::generateMap(AGameMap* gm)
{
	int** map = new int* [8];
	for (int i = 0; i < 8; ++i)
	{
		map[i] = new int[8];

		for (int j = 0; j < 8; ++j)
		{
			map[i][j] = gm->WhoOwnesTile(i, j);
		}
	}
	return map;
}

void AOutputService::setParams(AGameMap* gm, AGamePlayer* gp)
{
	PlayerSource = gp;
	TileMap = generateMap(gm);
	gold = gp->Gold;
	points = gp->Points;
	fertilizerActive = gp->fertilizerActive;
	bRainedThisTurn = gm->turn % 10;
	for (ACard* c : gp->Cards) {
		cards.insert(make_pair(c->id, c->owned));
	}
}
/*
Fstring AOutputService::convertToJSON(AGameMap* gm, AGamePlayer* gp)
{
	setParams(gm, gp);
	FString JsonRaw = "{ \"exampleString\": \"Hello World\" }";
	TSharedPtr<FJsonObject> JsonParsed;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		FString ExampleString = JsonParsed->GetStringField("exampleString");
	}
	return 
}*/

// Sets default values
AOutputService::AOutputService()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AOutputService::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AOutputService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}