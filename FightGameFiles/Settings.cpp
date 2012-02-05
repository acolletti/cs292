/*
 *  Settings.cpp
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/31/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Settings.h"

//Set the instance of settings to null until it is used
Settings* Settings::ptr = 0;

//Constructor
Settings::Settings()
{
  //this is temporary, but the values will be initialized here at first
  //Attack up variables
  doubleData["AttUpDuration"] = 0.75;
  doubleData["AttUpPrep"] = 0.25;
  doubleData["AttMidDuration"] = 0.75;
  doubleData["AttMidPrep"] = 0.25;
  doubleData["AttLowDuration"] = 0.75;
  doubleData["AttLowPrep"] = 0.25;
  doubleData["StaggerDuration"] = 0.75;
  doubleData["DefUpPrep"] = 0.50;
  doubleData["DefMidPrep"] = 0.50;
  doubleData["DefLowPrep"] = 0.50;
  doubleData["HitDuration"] = 0.50;
  doubleData["AdvanceDuration"] = 0.50;
}

//Instance function used to access the single instance of the singleton
Settings* Settings::Instance()
{
  if(!ptr)
  {
    ptr = new Settings();
  }
  return ptr;
}

//Get a double from the map; returns 0 if the key given is not in the map
double Settings::getDouble(std::string name)
{
  if(doubleData.find(name) == doubleData.end())
  {
    return 0;
  }
  
  return doubleData[name];
}

//Get a string from the map; returns "" if the key is not in the map
std::string Settings::getString(std::string name)
{
  if(stringData.find(name) == stringData.end())
  {
    return "";
  }
  
  return stringData[name];
}