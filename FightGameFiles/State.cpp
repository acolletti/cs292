/*
 *  State.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "State.h"
#include <string>

//Set up static variables to help identify different states
std::vector<std::string> State::names = std::vector<std::string>();
std::vector<State*> State::stateInstances = std::vector<State*>();

//Register a state by adding its name and pointer to the static
//vectors and returning its index in the vectors
int State::registerState(std::string name, State* state)
{
  int index = names.size();
  names.push_back(name);
  stateInstances.push_back(state);
  return index;
}

//This function returns the state's name if it has been registered
//NOTE: this function will fail if the state has not been registered
std::string State::getName()
{
  return names[stateID];
}

//This returns a state's instance based on the index number
//If the index number is invalid, a NULL pointer is returned
State* State::getState(int index)
{
  if(index >= 0 && index < stateInstances.size())
  {
    return stateInstances[index];
  }
  else
  {
    return NULL;
  }
}