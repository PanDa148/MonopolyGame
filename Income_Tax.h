#pragma once
#include "Space.h"
#include "Player.h"

class Income_Tax:public Space{
    public:
    Income_Tax();
    void action(Player& player, GameBoard& gb,std::vector<Player>& players);
};