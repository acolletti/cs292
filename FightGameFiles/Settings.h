/*
 *  Settings.h
 *  StateConcept
 *
 *  Created by Nancy Bailey on 1/31/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <map>
#include <string>

//This class holds constants that various parts of the program will use
//This will be used as a singleton and will store all values in a map
//that can be referenced through a string
//This can later be modified to read data from a file
class Settings
{
private:
  //Private constructor
  Settings();
  
  //Single instance of the Settings class
  static Settings* ptr;
  
  //Map of all the variables the class is holding
  //The data will be held in different maps according to the type
  std::map<std::string, double> doubleData;
  std::map<std::string, std::string> stringData;
  
public:
  //Returns the single instance of this class
  static Settings* Instance();
  
  //Data storage functions
  
  //Data accessing functions
  double getDouble(std::string name);
  std::string getString(std::string name);
  
};

#endif