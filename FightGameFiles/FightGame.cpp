/*
 *  FightGame.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "FightGame.h"
#include "Idle.h"
#include "Player.h"
#include <iostream>

//Constructor
FightGame::FightGame(std::string n1, std::string n2)
{
  players[0] = Player(this, n1);
  players[1] = Player(this, n2);
  players[0].changeState(Idle::Instance()->getStateID());
  players[1].changeState(Idle::Instance()->getStateID());
}

//Updates the game state
void FightGame::update(double delta)
{
  if(players[0].run(delta))
  {
    players[1].run(delta);
  }
}

//Get a player to change its state
//index is the index of the player, and state id determines which state
void FightGame::changeState(int index, int stateID)
{
  //Make sure the player index is valid
  if(index == 0 || index == 1)
  {
    players[index].changeState(stateID);
  }
}

//Print the current game state to the console
void FightGame::dumpState()
{
  for(int x = 0; x < 2; ++x)
  {
    std::cout << players[x].getName() << "\n";
    std::cout << "\tState: " << players[x].getState()->getName() << "\n";
    std::cout << "\tTime:  " << players[x].getStateTime() << "\n";
  }
}