/*
 *  DefendUp.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "DefendUp.h"
#include "AttackUp.h"
#include "Stagger.h"
#include "Idle.h"
#include "Player.h"
#include "FightGame.h"
#include "Settings.h"
#include <iostream>

DefendUp* DefendUp::ptr = NULL;

//This constructor needs to register the state
DefendUp::DefendUp() : prepTime(Settings::Instance()->getDouble("DefUpPrep"))
{
  stateID = State::registerState("Defend Up", this);
}

//Returns the single instance of the class
DefendUp* DefendUp::Instance()
{
  if(!ptr)
  {
    ptr = new DefendUp();
  }
  return ptr;
}

//Function called whenever the player enters this state
void DefendUp::enterState(Player* p)
{
  //Initialize the player variables
  p->setStateTime(0);
  p->setUserData(0);
  
  //Send a little message for debugging purposes
  std::cout << p->getName() << " has started an upper defence\n";
}

//This function is called when the state needs to update itself
bool DefendUp::run(Player* p, double delta)
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
void DefendUp::leaveState(Player* p)
{
  p->setStateTime(0);
  std::cout << p->getName() << " is leaving upper defense state\n";
}

//This function is called whenever a player receives a hit
bool DefendUp::hit(Player* p, int type)
{
  //Something needs to be added so that the player can tell what
  //Type of hit was dealt to it
  if(p->getStateTime() >= prepTime && type == AttackUp::Instance()->getStateID())
  {
    //std::cout << p->getName() << " was staggered while in attack state\n";
    return false;
  }
  else
  {
    std::cout << p->getName() << " was hit successfully while in upper defense\n";
    return true;
  }
}

//This function specifies whether or not the player can transition from
//This state to the given state
bool DefendUp::canTransition(Player* p, int index)
{
  //Can transition to idle only after defense has been held long enough
  if(index == Idle::Instance()->getStateID() && p->getStateTime() >= prepTime)
  {
    return true; 
  }
  
  //Can tranition to a hit or ko state... add later
  return false;
}