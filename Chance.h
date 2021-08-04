#pragma once
#include "Card_Space.h"
#include "Player.h"

class Chance : public Card_Space{
    public:
    Chance();
    static CardDeck cd;
    CardDeck* cards();
    void givePlayerCard(Player& p,Card* c);
};