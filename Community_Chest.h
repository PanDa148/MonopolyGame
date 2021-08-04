#pragma once
#include "Card_Space.h"
#include "Player.h"

class Community_Chest : public Card_Space{
    public:
    Community_Chest();
    static CardDeck cd;
    CardDeck* cards();
    void givePlayerCard(Player& p,Card* c);
};