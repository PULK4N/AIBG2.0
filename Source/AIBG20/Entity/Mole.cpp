// Fill out your copyright notice in the Description page of Project Settings.


#include "Mole.h"
#include "../Defines.h"

// Sets default values
AMole::AMole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Id = MOLE_CARD_ID;
	Owned = 0;
	Price = 8000;
}


