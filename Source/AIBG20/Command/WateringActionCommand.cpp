// Fill out your copyright notice in the Description page of Project Settings.


#include "WateringActionCommand.h"

WateringActionCommand::WateringActionCommand()
{
}

WateringActionCommand::~WateringActionCommand()
{
}

WateringActionCommand::WateringActionCommand(AGamePlayer* Player, int CoordinationX, int CoordinationY, ACard* Card, int AmountOfCards) 
{
    this->Player = Player;
    this.CoordinationX = CoordinationX;
    this.CoordinationY = CoordinationY;
    this.Card = Card;
    this.AmountOfCards = AmountOfCards;
}

void WateringActionCommand::Execute()
{
    if (CanExecute() == false)
        return;
    //if (CanExecute())
    //    Player->WaterPlant(1, FindTile());
}

bool WateringActionCommand::CanExecute()
{
    //int WaterCardId = 0;
    //for (ACard* card : Player->Cards) {
    //    if (HasWater() && OwnsPlantedTile())
    //            return true;
    //}
    return false;
}

bool WateringActionCommand::HasWater() {
    //for (ACard* card : Player->Cards) {
    //    if (card->Id == Card->Id) {
    //        return true;
    //    }
    //}
    return false;
}

bool WateringActionCommand::OwnsPlantedTile() {
    //ATile* tile = FindTile();
    //if(Player->Tiles.Find(tile)!=INDEX_NONE)
    //    return tile->bIsPlanted;
    return false;
}

ATile* WateringActionCommand::FindTile() {
    return nullptr;
}
