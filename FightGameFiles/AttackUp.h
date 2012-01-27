/*
 *  AttackUp.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ATTACKUP_H
#define ATTACKUP_H

#include "State.h"

class AttackUp : public State
{
protected:
  static AttackUp* ptr;
  //Timing variables
  double duration;  //Time before a hit is registered
  double prepTime;  //Time before the move is "active"
  
  //Private constructor to make it a singleton
  AttackUp();
  
public:
  
  //Creates the instance of the singleton
  static AttackUp* Instance();
  //Virtual functions from State class
  bool run(Player* p, double delta);
  bool hit(Player* p, int type);
  void enterState(Player* p);
  void leaveState(Player* p);
  bool canTransition(Player* p, int index);
};
  
#endif