#include "Community_Chest.h"
#include "Collect.h"
#include "Pay.h"
#include "GetOutOfJail.h"

Collect a2 ("Sell your life time, 50-yard line,season tickets on ebay",200);
Pay b2 ("Your computer network gets hit with a virus",1000);
GetOutOfJail c2 ("Receive a Presidential Pardon");

Card* cc_cards[3] = {&a2,&b2,&c2};

CardDeck Community_Chest::cd = CardDeck(cc_cards,sizeof(cc_cards)/sizeof(Card*));

Community_Chest::Community_Chest()
    :Card_Space("Community Chest")
{}

CardDeck* Community_Chest::cards() {
    return &cd;
}

void Community_Chest::givePlayerCard(Player& p,Card* c) {
    p.jailCard_cc=c;
}
