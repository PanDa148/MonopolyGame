#pragma once
#include "Space.h"
#include "Player.h"
#include "CardDeck.h"

class Card_Space : public Space {
    public:
    Card_Space(std::string name);
    void action(Player& player, GameBoard& gb,std::vector<Player>& players);
    virtual CardDeck* cards();
    virtual void givePlayerCard(Player& p,Card* c);
};