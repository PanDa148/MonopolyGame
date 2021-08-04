#include "GO.h"

GO::GO()
    :Space("Go")
{}
void GO::action(Player& player,  GameBoard& gb, std::vector<Player>& players) {
    player.cash+=2000;
}