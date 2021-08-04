#pragma once
#include "Space.h"
#include "Player.h"

class Go_To_Jail:public Space{
    public:
    Go_To_Jail();
    void action(Player& player, GameBoard& gb, std::vector<Player>& players);
};