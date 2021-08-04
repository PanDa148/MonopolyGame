#pragma once
#include "Card.h"

class Pay : public Card {
    private:
    int money;
    public:
    Pay(std::string new_text, int new_money);
    void action(Player& player);
};