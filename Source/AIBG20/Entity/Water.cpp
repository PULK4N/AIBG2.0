// Fill out your copyright notice in the Description page of Project Settings.


#include "Water.h"
#include "../Defines.h"

// Sets default values
AWater::AWater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Id = WATER_CARD_ID;
	Owned = 5;
	Price = 500;
}


