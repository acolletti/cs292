/*
 *  Idle.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef IDLE_H
#define IDLE_H

#include "State.h"

class Idle : public State
  {
  protected:
    static Idle* ptr;
    //Timing variables
    //Add later
    
    //Private constructor to make it a singleton
    Idle();
    
  public:
    
    //Creates the instance of the singleton
    static Idle* Instance();
    //Virtual functions from State class
    bool run(Player* p, double delta);
    bool hit(Player* p, int type);
    void enterState(Player* p);
    void leaveState(Player* p);
    bool canTransition(Player* p, int index);
  };

#endif