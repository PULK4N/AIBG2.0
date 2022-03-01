#pragma once

#include "CardDTO.generated.h"

USTRUCT()
struct FCardDTO
{
	GENERATED_BODY()

	UPROPERTY()
	int CardId;

	UPROPERTY()
	int Owned;

	FCardDTO(int cardId = 0, int owned = 0) : CardId(cardId), Owned(owned) {};
};
