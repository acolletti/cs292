#include <iostream>
#include "Player.h"
#include "AttackUp.h"
#include "DefendUp.h"
#include "FightGame.h"
#include "Idle.h"
#include <string>
#include <time.h>
#include <stdlib.h>

int main (int argc, char * const argv[]) {
  FightGame game("Freddy", "George");
  
  std::string input = "";
  int playerNum = 0;
  //clock_t time = clock();
  
  while(input != "q")
  {
    std::getline(std::cin, input);
    playerNum = atoi(input.c_str());
    if(playerNum == 0 || playerNum == 1)
    {
      std::getline(std::cin, input);
      State* newState = State::getState(input);
      if(newState && input != "Hit" && input != "Stagger" && input != "Advance")
      {
        game.changeState(playerNum, newState->getStateID());
      }
      else
      {
        game.dumpState();
      }
    }
    else
    {
      game.dumpState();
    }
    game.update(0.25);
  }
  std::cout << "Quitting game\n";
  return 0;
}
