// Fill out your copyright notice in the Description page of Project Settings.


#include "MoleCardActionCommand.h"
#include "../Entity/GameMap.h"
#include "../Defines.h"

MoleCardActionCommand::MoleCardActionCommand()
{
}

MoleCardActionCommand::~MoleCardActionCommand()
{
    UE_LOG(LogTemp, Warning, TEXT("MoleCardActionCommand deleted"));
}

MoleCardActionCommand::MoleCardActionCommand(AGamePlayer* Player, int CoordinationX, int CoordinationY, int CardID, int AmountOfCards)
{
    this->Player = Player;
    this->CoordinationX = CoordinationX;
    this->CoordinationY = CoordinationY;
    this->CardID = CardID;
    this->Amount = AmountOfCards;
}

void MoleCardActionCommand::Execute()
{
    if (CanExecute() == false) {
        return;
    }
    Player->FindCardById(MOLE_CARD_ID)->Owned--;
    ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
    DestroyPlantIfPlanted(tile);
    AddTileToPlayer(tile);
    RemoveTileFromEnemy(tile);
    ATile::OWNER owner = Player == GameMap->Player1 ? ATile::OWNER::PLAYER_1 : ATile::OWNER::PLAYER_2;
    tile->ChangeMeshComponent(owner);
    UE_LOG(LogTemp, Warning, TEXT("Mole action executed"));
}

bool MoleCardActionCommand::CanExecute()
{
    if (Player->FindCardById(MOLE_CARD_ID)->Owned <= 0) {
        UE_LOG(LogTemp, Warning, TEXT("Mole action couldn't execute because player doesn't own any moles"));
        return false;
    }
    ATile* tile = GameMap->FindTile(CoordinationX, CoordinationY);
    if (GameMap->Player1 == Player) {
        if (EnemyOwnsTheTile(GameMap->Player2, tile)) {
            return true;
        }
    }
    else if (GameMap->Player2 == Player) {
        if (EnemyOwnsTheTile(GameMap->Player1, tile)) {
            return true;
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("Mole action couldn't execute because enemy player doesn't own the tile"));
    return false;
}

bool MoleCardActionCommand::EnemyOwnsTheTile(AGamePlayer* enemy, ATile* tile) {
    if (enemy->Tiles.Find(tile) == INDEX_NONE) {
        return false;
    }
    return true;
}

void MoleCardActionCommand::DestroyPlantIfPlanted(ATile* tile) {
    if (tile->bIsPlanted) {
        tile->Plant->Destroy();
        tile->bIsPlanted = false;
    }
}

void MoleCardActionCommand::RemoveTileFromEnemy(ATile* tile) {
    if (GameMap->Player1 == Player) {
        GameMap->Player2->Tiles.Remove(tile);
    }
    else {
        GameMap->Player1->Tiles.Remove(tile);
    }
}

void MoleCardActionCommand::AddTileToPlayer(ATile* tile) {
    Player->Tiles.Add(tile);
}