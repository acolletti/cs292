/*
 *  AttackMid.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ATTACKMID_H
#define ATTACKMID_H

#include "State.h"

class AttackMid : public State
  {
  protected:
    static AttackMid* ptr;
    //Timing variables
    double duration;  //Time before a hit is registered
    double prepTime;  //Time before the move is "active"
    
    //Private constructor to make it a singleton
    AttackMid();
    
  public:
    
    //Creates the instance of the singleton
    static AttackMid* Instance();
    //Virtual functions from State class
    bool run(Player* p, double delta);
    bool hit(Player* p, int type);
    void enterState(Player* p);
    void leaveState(Player* p);
    bool canTransition(Player* p, int index);
  };

#endif