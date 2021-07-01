#include <string>
#include <vector>
#include <iostream>
#include "Monopoly.h"
#include <algorithm>

int main()
{
    std::cout<<"Welcome to monopoly!\n";
    Monopoly monopoly;
    monopoly.assign_players();
    monopoly.manage_player_turns();
    monopoly.end_game();
}
