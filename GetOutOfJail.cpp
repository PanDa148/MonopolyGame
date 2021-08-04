#include "GetOutOfJail.h"

GetOutOfJail::GetOutOfJail(std::string new_text)
    : Card(new_text,1)
{}

void GetOutOfJail::action(Player& player) {
    Card::action(player);
    std::cout<<"GET OUT OF JAIL FREE.\n";
    std::cout<<"This card may be kept until needed or sold.\n";
}