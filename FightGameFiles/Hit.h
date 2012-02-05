/*
 *  Hit.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef HIT_H
#define HIT_H

#include "State.h"

class Hit : public State
{
protected:
  static Hit* ptr;
  //Timing variables
  double duration;  //Time a player is stuck in this state
  
  //Private constructor to make it a singleton
  Hit();
  
public:
  
  //Creates the instance of the singleton
  static Hit* Instance();
  //Virtual functions from State class
  bool run(Player* p, double delta);
  bool hit(Player* p, int type);
  void enterState(Player* p);
  void leaveState(Player* p);
  bool canTransition(Player* p, int index);
};
  
#endif