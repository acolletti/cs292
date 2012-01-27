/*
 *  Player.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/23/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "State.h"

class FightGame;

class Player
{
protected:
  std::string name;
  int position;
  int health;
  double stateTime;
  int id;
  State* currentState;
  FightGame* owner;
  bool go;  //Used to determine if a player can go in a round
  
  int userData; //Member data used by the states
  
  static int idCount;
  
public:
  //Constructor
  Player(FightGame* o, std::string n);
  Player() {}
  
  //executes one time interval of the game
  bool run(double delta);
  
  //Attempts to change the state
  void changeState(int state);
  void forceChange(int state);
  
  //Accessor functions
  std::string getName() {return name;}
  FightGame* getOwner() {return owner;}
  int getUserData() {return userData;}
  double getStateTime() {return stateTime;}
  State* getState() {return currentState;}
  bool canGo() {return go;}
  
  //Modifier functions
  void setUserData(int d) {userData = d;}
  void incStateTime(double d) {stateTime += d;}
  void setStateTime(double d) {stateTime = d;}
  void setGo(bool g) {go = g;}
  
};

#endif PLAYER_H