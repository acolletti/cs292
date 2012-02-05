/*
 *  DefendMid.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DEFENDMID_H
#define DEFENDMID_H

#include "State.h"

class DefendMid : public State
  {
  protected:
    static DefendMid* ptr;
    //Timing variables
    double prepTime;  //Time before the move is "active"
    
    //Private constructor to make it a singleton
    DefendMid();
    
  public:
    
    //Creates the instance of the singleton
    static DefendMid* Instance();
    //Virtual functions from State class
    bool run(Player* p, double delta);
    bool hit(Player* p, int type);
    void enterState(Player* p);
    void leaveState(Player* p);
    bool canTransition(Player* p, int index);
  };

#endif