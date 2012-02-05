/*
 *  AttackMid.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "AttackMid.h"
#include "Stagger.h"
#include "Idle.h"
#include "Player.h"
#include "Hit.h"
#include "Advance.h"
#include "FightGame.h"
#include "Settings.h"
#include <iostream>

AttackMid* AttackMid::ptr = NULL;

//This constructor needs to register the state
AttackMid::AttackMid() : duration(Settings::Instance()->getDouble("AttMidDuration")),
prepTime(Settings::Instance()->getDouble("AttMidPrep"))
{
  stateID = State::registerState("Attack Mid", this);
}

//Returns the single instance of the class
AttackMid* AttackMid::Instance()
{
  if(!ptr)
  {
    ptr = new AttackMid();
  }
  return ptr;
}

//Function called whenever the player enters this state
void AttackMid::enterState(Player* p)
{
  //Initialize the player variables
  p->setStateTime(0);
  p->setUserData(0);
  
  //Send a little message for debugging purposes
  std::cout << p->getName() << " has started a mid attack\n";
}

//This function is called when the state needs to update itself
bool AttackMid::run(Player* p, double delta)
{
  //Update player timer
  p->incStateTime(delta);
  
  //Do some checks to see if this state is done executing
  if(p->getStateTime() >= duration)
  {
    //Register a hit on the other player
    Player* other = p->getOwner()->getOtherPlayer(p);
    bool success = other->getState()->hit(other, getStateID());
    
    //Either go to a staggered state or advance if success or not
    if(success)
    {
      std::cout << p->getName() << " succeeded in mid attack\n";
      p->forceChange(Advance::Instance()->getStateID());
      other->forceChange(Hit::Instance()->getStateID());
      return false;
    }
    else
    {
      p->forceChange(Stagger::Instance()->getStateID());
      if(other->changeState(Stagger::Instance()->getStateID()))
        return false;
    }
  }
  return true;
}

//This function is called when the player leaves the state
void AttackMid::leaveState(Player* p)
{
  p->setStateTime(0);
  std::cout << p->getName() << " is leaving mid attack state\n";
}

//This function is called whenever a player receives a hit
bool AttackMid::hit(Player* p, int type)
{
  //Something needs to be added so that the player can tell what
  //Type of hit was dealt to it
  if(p->getStateTime() >= prepTime)
  {
    //std::cout << p->getName() << " was staggered while in attack state\n";
    return false;
  }
  else
  {
    std::cout << p->getName() << " was hit successfully while in attack state\n";
    return true;
  }
}

//This function specifies whether or not the player can transition from
//This state to the given state
bool AttackMid::canTransition(Player* p, int index)
{
  if(index == Stagger::Instance()->getStateID())
  {
    return true;
  }
  //Can only tranition to a hit or ko state... add later
  return false;
}