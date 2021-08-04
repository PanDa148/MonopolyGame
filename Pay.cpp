#include "Pay.h"
#include "Player.h"

Pay::Pay(std::string new_text, int new_money)
    : Card(new_text)
    , money(new_money)
{}

void Pay::action(Player& player) {
    Card::action(player);
    std::cout<<"PAY $"<<money<<"\n";
    player.cash-=money;
}