/*
 *  Idle.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Idle.h"
#include "Player.h"
#include <iostream>

Idle* Idle::ptr = NULL;

//This constructor needs to register the state
Idle::Idle()
{
  stateID = State::registerState("Idle", this);
}

//Returns the single instance of the class
Idle* Idle::Instance()
{
  if(!ptr)
  {
    ptr = new Idle();
  }
  return ptr;
}

//Function called whenever the player enters this state
void Idle::enterState(Player* p)
{
  //Initialize the player variables
  p->setStateTime(0);
  p->setUserData(0);
  
  //Send a little message for debugging purposes
  std::cout << p->getName() << " has entered idle state\n";
}

//This function is called when the state needs to update itself
bool Idle::run(Player* p, double delta)
{
  //Update player timer
  
  //Do some checks to see if this state is done executing
  return true;
}

//This function is called when the player leaves the state
void Idle::leaveState(Player* p)
{
  std::cout << p->getName() << " is leaving idle state\n";
}

//This function is called whenever a player receives a hit
bool Idle::hit(Player* p, int type)
{
  //Something needs to be added so that the player can tell what
  //Type of hit was dealt to it
  std::cout << p->getName() << " was hit while idle\n";
  return true;
}

//This function specifies whether or not the player can transition from
//This state to the given state
bool Idle::canTransition(Player* p, int index)
{
  //Can only tranition to any state
  return true;
}