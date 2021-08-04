#pragma once
#include "Card.h"

class Collect : public Card {
    private:
    int money;
    public:
    Collect(std::string new_text, int new_money);
    void action(Player& player);
};