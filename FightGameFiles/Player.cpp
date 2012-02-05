/*
 *  Player.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/23/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Player.h"

#include <string>

int Player::idCount = 0;

//Constructor
//n is the name of the robot
Player::Player(FightGame* o, std::string n) : name (n),
                                              position(0),
                                              health(100),
                                              stateTime(0.0),
                                              id(0),
                                              currentState(NULL),
                                              owner(o)
{
  //Give the player a unique id for identifying it later
  id = idCount++;
}

//This updates the state the player is in by the given time interval
bool Player::run(double delta)
{
  if(currentState)
  {
    return currentState->run(this, delta);
  }
  return true;
}

//This attempts to change the state of the player
bool Player::changeState(int state)
{
  //Make sure the player is already in a state
  if(currentState)
  {
    State* nextState = State::getState(state);
    if(nextState) //Make sure the next state is valid
    {
      //See if the player can switch to this state
      if(currentState->canTransition(this, state))
      {
         currentState->leaveState(this);
         currentState = nextState;
         currentState->enterState(this);
        return true;
      }
    }
  }
  else //Automatically switch to this state since there isn't a previous one
  {
    currentState = State::getState(state);
    if(currentState)
    {
      currentState->enterState(this);
    }
    return true;
  }
  return false;
}

//This forces a state change and ignores if it can or not
void Player::forceChange(int state)
{
  if(currentState)
  {
    currentState->leaveState(this);
  }
  currentState = State::getState(state);
  if(currentState)
  {
    currentState->enterState(this);
  }
}