/*
 *  Hit.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Hit.h"
#include "Idle.h"
#include "Player.h"
#include "FightGame.h"
#include "Settings.h"
#include <iostream>

Hit* Hit::ptr = NULL;

//This constructor needs to register the state
Hit::Hit() : duration(Settings::Instance()->getDouble("HitDuration"))
{
  stateID = State::registerState("Hit", this);
}

//Returns the single instance of the class
Hit* Hit::Instance()
{
  if(!ptr)
  {
    ptr = new Hit();
  }
  return ptr;
}

//Function called whenever the player enters this state
void Hit::enterState(Player* p)
{
  //Initialize the player variables
  p->setStateTime(0);
  p->setUserData(0);
  
  //Send a little message for debugging purposes
  std::cout << p->getName() << " has been hit\n";
}

//This function is called when the state needs to update itself
bool Hit::run(Player* p, double delta)
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
void Hit::leaveState(Player* p)
{
  std::cout << p->getName() << " is leaving hit state\n";
}

//This function is called whenever a player receives a hit
bool Hit::hit(Player* p, int type)
{
  //The player is always vulnerable in a stagger
  return true;
}

//This function specifies whether or not the player can transition from
//This state to the given state
bool Hit::canTransition(Player* p, int index)
{
  //Can only tranition to a hit or ko state... add later
  return false;
}