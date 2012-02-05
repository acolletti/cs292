/*
 *  DefendLow.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DEFENDLOW_H
#define DEFENDLOW_H

#include "State.h"

class DefendLow : public State
  {
  protected:
    static DefendLow* ptr;
    //Timing variables
    double prepTime;  //Time before the move is "active"
    
    //Private constructor to make it a singleton
    DefendLow();
    
  public:
    
    //Creates the instance of the singleton
    static DefendLow* Instance();
    //Virtual functions from State class
    bool run(Player* p, double delta);
    bool hit(Player* p, int type);
    void enterState(Player* p);
    void leaveState(Player* p);
    bool canTransition(Player* p, int index);
  };

#endif