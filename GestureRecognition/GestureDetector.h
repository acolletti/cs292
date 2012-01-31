/*
 *  GestureDetector.h
 *  GestureRecognition
 *
 *  Created by Nancy Bailey on 1/31/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GESTUREDETECTOR_H
#define GESTUREDETECTOR_H

//This defines a class that holds various gestures and attempts
//to match current input to one of those gestures
class GestureDetector
{
protected:
  //This function calculates the distance between the point and the line segment
  double distanceSq();
  
  //This takes the current input position, the frame in the gesture, and
  //the joint in the gesture and calculates a tolorance level
  double detectGestureJoint();
  
  //This takes in all current joint positions, a gesture, and a frame number
  //in the gesture to check and returns the next frame number for the gesture
  //the returned frame number can either be 0, the same number, or the next
  //frame number in the gesture
  int detectGesture();
  
  //Member data:
  //This class needs to hold the data for every gesture it wants to recognize
  //(can be implemented by having a separate gesture class, and this class
  //has different instances of that class for each gesture it needs to track
  //
  //A vector of the current frames on each gesture
  //
  //progress on each from for each gesture (how far into the frame has the
  //user progressed?)
  //This will be a value between 0 and 1. 0 indicates the user is exactly on the
  //beginning of the current frame stored in the data member above, and
  //a 1 indicates the user is on the next frame
  //This will be stored in a vector of some sort
  //
  //A vector of the previously calculated tolorance values for each gesture
  //this will be the value calculated in the detectGestureJoint and might
  //go through some more processing.  This value will be smoothed to help
  //reduce noise from the input that might prevent gestures from being
  //detected
  
public:
  //This function takes all current joint positions as an input and attempts
  //to detect gestures
  void processInput();
  
};

#enif