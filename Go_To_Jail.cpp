#include "Go_To_Jail.h"

Go_To_Jail::Go_To_Jail()
    :Space("Go To Jail")
{}
void Go_To_Jail::action(Player& player,  GameBoard& gb, std::vector<Player>& players) {
    std::cout<<"Go to jail!!!";
    player.in_jail=true;
    player.position=11;
}