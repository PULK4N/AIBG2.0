// Fill out your copyright notice in the Description page of Project Settings.


#include "MoleCardActionCommand.h"

MoleCardActionCommand::MoleCardActionCommand()
{
}

MoleCardActionCommand::~MoleCardActionCommand()
{
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
