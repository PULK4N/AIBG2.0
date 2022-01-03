#pragma once

#include "CardDTO.generated.h"

USTRUCT()
struct FCardDTO
{
	GENERATED_BODY()

	UPROPERTY()
	int Id;

	UPROPERTY()
	int Owned;

	FCardDTO(int id = 0, int owned = 0) : Id(id), Owned(owned) {};
};
