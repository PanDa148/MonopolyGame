#pragma once
#include "Space.h"
#include "Player.h"

class Interest_on_credit_card_debt:public Space{
    public:
    Interest_on_credit_card_debt();
    void action(Player& player, GameBoard& gb,std::vector<Player>& players);
};