/*
 *  DefendMid.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "DefendMid.h"
#include "AttackMid.h"
#include "Stagger.h"
#include "Idle.h"
#include "Player.h"
#include "FightGame.h"
#include "Settings.h"
#include <iostream>

DefendMid* DefendMid::ptr = NULL;

//This constructor needs to register the state
DefendMid::DefendMid() : prepTime(Settings::Instance()->getDouble("DefMidPrep"))
{
  stateID = State::registerState("Defend Mid", this);
}

//Returns the single instance of the class
DefendMid* DefendMid::Instance()
{
  if(!ptr)
  {
    ptr = new DefendMid();
  }
  return ptr;
}

//Function called whenever the player enters this state
void DefendMid::enterState(Player* p)
{
  //Initialize the player variables
  p->setStateTime(0);
  p->setUserData(0);
  
  //Send a little message for debugging purposes
  std::cout << p->getName() << " has started a mid defence\n";
}

//This function is called when the state needs to update itself
bool DefendMid::run(Player* p, double delta)
{
  //Update player timer
  if(p->getStateTime() < prepTime)
  {
    p->incStateTime(delta);
  }
  
  //Always return true to indicate the other player can also be updated
  return true;
}

//This function is called when the player leaves the state
void DefendMid::leaveState(Player* p)
{
  p->setStateTime(0);
  std::cout << p->getName() << " is leaving middle defense state\n";
}

//This function is called whenever a player receives a hit
bool DefendMid::hit(Player* p, int type)
{
  //Something needs to be added so that the player can tell what
  //Type of hit was dealt to it
  if(p->getStateTime() >= prepTime && type == AttackMid::Instance()->getStateID())
  {
    //std::cout << p->getName() << " was staggered while in attack state\n";
    return false;
  }
  else
  {
    std::cout << p->getName() << " was hit successfully while in mid defense\n";
    return true;
  }
}

//This function specifies whether or not the player can transition from
//This state to the given state
bool DefendMid::canTransition(Player* p, int index)
{
  //Can transition to idle only after defense has been held long enough
  if(index == Idle::Instance()->getStateID() && p->getStateTime() >= prepTime)
  {
    return true; 
  }
  
  //Can tranition to a hit or ko state... add later
  return false;
}