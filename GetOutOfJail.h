#pragma once
#include "Card.h"

class GetOutOfJail : public Card {
    public:
    GetOutOfJail(std::string new_text);
    void action(Player& player);
};