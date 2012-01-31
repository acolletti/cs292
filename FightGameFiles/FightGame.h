/*
 *  FightGame.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

//This class handles all of the data transfer required for input
//and output of the fighting game.  Everything related to that part of
//the game is contained within this class

#ifndef FIGHTGAME_H
#define FIGHTGAME_H

#include "Player.h"
#include <string>

class FightGame
{
protected:
  Player players[2]; //The two player classes fighting each other
  
public:
  //constructor
  FightGame(std::string n1, std::string n2);
  
  //runs the game through the specified amount of time
  void update(double delta);
  
  //Returns the player that isn't given as the argument
  Player* getOtherPlayer(Player* p) {return (players == p ? players + 1 : players);}
  
  //This attempts to get a player to change a state
  void changeState(int index, int stateID);
  
  //Dumps the state of the game to console out (for debugging purposes)
  void dumpState();
};
  
#endif