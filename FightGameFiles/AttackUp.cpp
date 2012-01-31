/*
 *  AttackUp.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "AttackUp.h"
#include "Stagger.h"
#include "Idle.h"
#include "Player.h"
#include "FightGame.h"
#include "Settings.h"
#include <iostream>

AttackUp* AttackUp::ptr = NULL;

//This constructor needs to register the state
AttackUp::AttackUp() : duration(Settings::Instance()->getDouble("AttUpDuration")),
                       prepTime(Settings::Instance()->getDouble("AttUpPrep"))
{
  stateID = State::registerState("Attack Up", this);
}

//Returns the single instance of the class
AttackUp* AttackUp::Instance()
{
  if(!ptr)
  {
    ptr = new AttackUp();
  }
  return ptr;
}

//Function called whenever the player enters this state
void AttackUp::enterState(Player* p)
{
  //Initialize the player variables
  p->setStateTime(0);
  p->setUserData(0);
  
  //Send a little message for debugging purposes
  std::cout << p->getName() << " has started an upper attack\n";
}

//This function is called when the state needs to update itself
bool AttackUp::run(Player* p, double delta)
{
  //Update player timer
  p->incStateTime(delta);
  
  //Do some checks to see if this state is done executing
  if(p->getStateTime() >= duration)
  {
    //Register a hit on the other player
    Player* other = p->getOwner()->getOtherPlayer(p);
    bool success = other->getState()->hit(other, 0);
    
    //Either go to a staggered state or idle if success or not
    if(success)
    {
      std::cout << p->getName() << " succeeded in up attack\n";
      p->forceChange(Idle::Instance()->getStateID());
    }
    else
    {
      p->forceChange(Stagger::Instance()->getStateID());
      other->forceChange(Stagger::Instance()->getStateID());
    }
    return false;
  }
  return true;
}

//This function is called when the player leaves the state
void AttackUp::leaveState(Player* p)
{
  p->setStateTime(0);
  std::cout << p->getName() << " is leaving upper attack state\n";
}

//This function is called whenever a player receives a hit
bool AttackUp::hit(Player* p, int type)
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
bool AttackUp::canTransition(Player* p, int index)
{
  //Can only tranition to a hit or ko state... add later
  return false;
}