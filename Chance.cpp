#include "Chance.h"
#include "Collect.h"
#include "Pay.h"
#include "GetOutOfJail.h"

Collect a1 ("Get a tax break for driving a hybrid", 500);
Pay b1 ("Make a donation for Disaster Relief",150);
GetOutOfJail c1 ("You are acquitted");

Card* c_cards[3] = {&a1,&b1,&c1};

CardDeck Chance::cd = CardDeck(c_cards,sizeof(c_cards)/sizeof(Card*));

Chance::Chance()
    :Card_Space("Chance")
{}

CardDeck* Chance::cards() {
    return &cd;
}

void Chance::givePlayerCard(Player& p,Card* c) {
    p.jailCard_c=c;
}
