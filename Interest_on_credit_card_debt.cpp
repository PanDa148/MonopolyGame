#include "Interest_on_credit_card_debt.h"

Interest_on_credit_card_debt::Interest_on_credit_card_debt()
    :Space("Interest on credit card debt")
{}
void Interest_on_credit_card_debt::action(Player& player, GameBoard& gb,std::vector<Player>& players) {
    player.cash-=750;
    std::cout<<"You paid $750\n";
}