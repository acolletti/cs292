/*
 *  Advance.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Advance.h"
#include "Idle.h"
#include "Player.h"
#include "FightGame.h"
#include "Settings.h"
#include <iostream>

Advance* Advance::ptr = NULL;

//This constructor needs to register the state
Advance::Advance() : duration(Settings::Instance()->getDouble("AdvanceDuration"))
{
  stateID = State::registerState("Advance", this);
}

//Returns the single instance of the class
Advance* Advance::Instance()
{
  if(!ptr)
  {
    ptr = new Advance();
  }
  return ptr;
}

//Function called whenever the player enters this state
void Advance::enterState(Player* p)
{
  //Initialize the player variables
  p->setStateTime(0);
  p->setUserData(0);
  
  //Send a little message for debugging purposes
  std::cout << p->getName() << " is advancing\n";
}

//This function is called when the state needs to update itself
bool Advance::run(Player* p, double delta)
{
  //Update player timer
  p->incStateTime(delta);
  
  //Do some checks to see if this state is done executing
  if(p->getStateTime() >= duration)
  {
    //Go back to idle state
    p->forceChange(Idle::Instance()->getStateID());
  }
  
  //Do something to update the player's position
  //Add later
  
  return true;
}

//This function is called when the player leaves the state
void Advance::leaveState(Player* p)
{
  std::cout << p->getName() << " is leaving advance state\n";
}

//This function is called whenever a player receives a hit
bool Advance::hit(Player* p, int type)
{
  //The player is always vulnerable in a stagger
  return true;
}

//This function specifies whether or not the player can transition from
//This state to the given state
bool Advance::canTransition(Player* p, int index)
{
  //Can only tranition to a hit or ko state... add later
  return false;
}