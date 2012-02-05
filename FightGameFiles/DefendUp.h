/*
 *  DefendUp.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DEFENDUP_H
#define DEFENDUP_H

#include "State.h"

class DefendUp : public State
{
protected:
  static DefendUp* ptr;
  //Timing variables
  double prepTime;  //Time before the move is "active"
  
  //Private constructor to make it a singleton
  DefendUp();
  
public:
  
  //Creates the instance of the singleton
  static DefendUp* Instance();
  //Virtual functions from State class
  bool run(Player* p, double delta);
  bool hit(Player* p, int type);
  void enterState(Player* p);
  void leaveState(Player* p);
  bool canTransition(Player* p, int index);
};
  
#endif