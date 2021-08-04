#include "Collect.h"
#include "Player.h"

Collect::Collect(std::string new_text, int new_money)
    : Card(new_text)
    , money(new_money)
{}

void Collect::action(Player& player) {
    Card::action(player);
    std::cout<<"COLLECT $"<<money<<"\n";
    player.cash+=money;
}