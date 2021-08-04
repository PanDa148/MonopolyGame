#include "Card_Space.h"
#include "GetOutOfJail.h"

Card_Space::Card_Space(std::string name)
    :Space(name)
{}

CardDeck* Card_Space::cards() {
    return NULL;
}

void Card_Space::givePlayerCard(Player& player, Card* c) {}

void Card_Space::action(Player& player, GameBoard& gb,std::vector<Player>& players) {
    Card* c = cards()->drawCard();
    std::cout<<name<<"\n";
    c->action(player);
    if (c->jail) {
        givePlayerCard(player,c);
    }
}