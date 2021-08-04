#pragma once
#include "Space.h"
#include "Player.h"

class GO:public Space{
  public:
  GO();
  void action(Player& player,  GameBoard& gb, std::vector<Player>& players);
};