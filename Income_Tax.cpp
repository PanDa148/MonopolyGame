#include "Income_Tax.h"

Income_Tax::Income_Tax()
    :Space("Income Tax")
{}
void Income_Tax::action(Player& player,  GameBoard& gb, std::vector<Player>& players) {
	int tax=player.calc_net_worth(gb)*0.1;
	if (tax<2000){
		std::cout<<"You paid $"<<tax<<".\n";
		player.cash-=tax;
	}
	else{
		std::cout<<"You paid $2000.\n";
		player.cash-=2000;
	
	}
}