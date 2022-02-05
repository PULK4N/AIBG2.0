#pragma once

#include "CardDTO.h"
#include "TileDTO.h"
#include "GamePlayerDTO.generated.h"


USTRUCT()
struct FGamePlayerDTO
{
	GENERATED_BODY()

	UPROPERTY()
	int Points;
	UPROPERTY()
	int Gold;
	UPROPERTY()
	int FertilizerActive;

	UPROPERTY()
	TArray<FTileDTO> Tiles;
	UPROPERTY()
	TArray<FCardDTO> Cards;

	FGamePlayerDTO(int points = 0, int gold = 0, int fertilizerActive = 0)
		: Points(points), Gold(gold), FertilizerActive(fertilizerActive) {};

	//FGamePlayerDTO(int points = 0, int gold = 0, int fertilizerActive = 0,
	//TArray<FTileDTO> tiles = TArray<FTileDTO>(), TArray<FCardDTO> cards = TArray<FCardDTO>())
	//: Points(points), Gold(gold), FertilizerActive(fertilizerActive), Tiles(tiles)
	//Cards(cards){};
};