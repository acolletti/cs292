#include <iostream>
#include "Player.h"
#include "AttackUp.h"
#include "FightGame.h"
#include "Idle.h"
#include <string>
#include <time.h>

int main (int argc, char * const argv[]) {
  FightGame game("Freddy", "George");
  
  std::string input = "";
  //clock_t time = clock();
  
  while(input != "q")
  {
    std::cin >> input;
    if(input == "a")
    {
      game.changeState(0, AttackUp::Instance()->getStateID());
    }
    else if(input == "b")
    {
      game.changeState(1, AttackUp::Instance()->getStateID());
    }
    else if(input == "d")
    {
      game.dumpState();
    }
    game.update(0.25);
  }
  std::cout << "Quitting game\n";
  return 0;
}
