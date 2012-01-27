/*
 *  Stagger.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef STAGGER_H
#define STAGGER_H

#include "State.h"

class Stagger : public State
{
protected:
  static Stagger* ptr;
  //Timing variables
  double duration;  //Time a player is stuck in this state
  
  //Private constructor to make it a singleton
  Stagger();
  
public:
  
  //Creates the instance of the singleton
  static Stagger* Instance();
  //Virtual functions from State class
  bool run(Player* p, double delta);
  bool hit(Player* p, int type);
  void enterState(Player* p);
  void leaveState(Player* p);
  bool canTransition(Player* p, int index);
};
  
#endif