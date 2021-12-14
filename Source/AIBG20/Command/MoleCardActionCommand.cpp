// Fill out your copyright notice in the Description page of Project Settings.


#include "MoleCardActionCommand.h"

MoleCardActionCommand::MoleCardActionCommand()
{
}

MoleCardActionCommand::~MoleCardActionCommand()
{
}

MoleCardActionCommand::MoleCardActionCommand(AGamePlayer* Player, int CoordinationX, int CoordinationY, ACard* Card, int AmountOfCards)
{
    this->Player = Player;
    this->CoordinationX = CoordinationX;
    this->CoordinationY = CoordinationY;
    this->Card = Card;
    this->AmountOfCards = AmountOfCards;
}

void MoleCardActionCommand::Execute()
{
    if (CanExecute() == false)
        return;
}

bool MoleCardActionCommand::CanExecute()
{
    return false;
}
