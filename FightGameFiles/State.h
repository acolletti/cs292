/*
 *  State.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/23/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>

//Describes a base class of a state that each player will be in
//The state will be implemented as a singleton and will modify
//A few variables within the player object

class Player;

class State
{
protected:
  static std::vector<std::string> names;     //Used for looking up a state by name
  static std::vector<State*> stateInstances; //Used for accessing a state by name
  
  //Unique number identifying the state after it has been registered
  int stateID;
  
public:
  virtual bool run(Player* p, double delta) = 0;
  virtual bool hit(Player* p, int type) = 0;
  virtual void enterState(Player* p) = 0;
  virtual void leaveState(Player* p) = 0;
  virtual bool canTransition(Player* p, int index) = 0;
  
  //Accessor functions
  int getStateID() {return stateID;}
  std::string getName();
  static State* getState(int index);
  
  //Registers a state and returns a unique number that identifies it
  static int registerState(std::string name, State* state);
};

#endif