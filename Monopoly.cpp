#include <iostream>
#include <cmath>
#include <algorithm>
#include "Monopoly.h"
#include <thread>
#include <chrono>

Monopoly::Monopoly(){
	std::cout<<"Welcome to monopoly!\n";
}
Monopoly::~Monopoly(){
	std::cout<<"Bye!\n";
}

void Monopoly::assign_players() {
    int num_players=0;
	std::string input="";
    Player null_player(" ");
    players.push_back(null_player);
    std::vector<std::string> mascots {"Dog","Ship","Coffee","Laptop","Shoe","McDonald's Cup","Airplane","Cellphone"};
    while(num_players<1 || num_players>8){
        std::cout<<"How many players?(1-8)\n";
        std::cin>>input;
		try {
			num_players=stoi(input);
		} catch (...) {
			std::cout<<"Invalid input\n";
		}
    }
    int player_num=1;
    while (player_num<=num_players) {
        int choice=-1;
        std::string input;
        std::cout<<"Which token does player "<<player_num<<" want to be?\n";
        for (int i=0; i<mascots.size(); i++) {
            std::cout<<i+1<<": "<<mascots[i]<<"\n";
        }
        std::cin>>input;
		try {
        	choice = stoi(input)-1;
		}
		catch (...) {
			std::cout<<"Invalid input\n";
		}
        if (choice>=0 && choice<mascots.size()) {
            Player player(mascots[choice]);
            players.push_back(player);
            mascots.erase(mascots.begin()+choice);
            player_num++;
        }
        else {
            std::cout<<"Invalid input\n";
            std::cout<<"Try again\n";
        }
    }
}

void Monopoly::end_game() {
    int highest_net_worth=0;
    for (int x=1; x<players.size();x++){
		Player& player=players[x];
		int cur_net_worth=player.calc_net_worth(gb);
		if (cur_net_worth>=highest_net_worth){
			highest_net_worth=cur_net_worth;
		}
    }
    std::vector<std::string> winners;
    for (int x=1; x<players.size(); x++){
	if (players[x].net_worth==highest_net_worth){
	    winners.push_back(players[x].get_name());
	}
    }
    if (winners.size()==1){
	std::cout<<winners[0]<<" won with a net worth of $"<<highest_net_worth<<"!\n";
    }
    else if (winners.size()==2){
	std::cout<<winners[0]<<" and "<<winners[1]<<" won with a net worth of $"<<highest_net_worth<<"!\n";
    }
    else{
	for (int x=0; x<(winners.size()-1); x++) {
	    std::cout<<winners[x]<<", ";
	}
	std::cout<<"and "<<winners[winners.size()-1]<<" won with a net worth of $"<<highest_net_worth<<"!\n";
    }
}

void Monopoly::take_mortgage(Player& player) {
	if (is_bankrupt(player)) {
		std::cout<<"You are bankrupt!\n You lose!\n";
	} else {
	std::string input;
	int choice = -1;
	std::cout<<"Which property do you want to mortgage?\n";
	std::vector<int> properties_to_mortgage;
	for (int x = 0; x<40; x++){
		Space* chosen = gb[x];
		if ((chosen->owner == player.get_name()) && !(chosen->mortgaged)){
			properties_to_mortgage.push_back(x);
		}
	}
	if (properties_to_mortgage.size()>0) {
		while (choice<0 && choice>=properties_to_mortgage.size()) {
			for (int x=0; x<properties_to_mortgage.size(); x++){
				int i = properties_to_mortgage[x];
				Space* p = gb[i];
				std::cout<<x<<": "<<p->get_name()<<" for $"<<p->get_mortgage_value()<<"\n";
			}
			std::cin>>input;
			try {
				choice = stoi(input);
			}
			catch (...) {
				std::cout<<"Invalid input\n";
			}
		}
		Space* chosen = gb[properties_to_mortgage[choice]];
		player.cash+=chosen->get_mortgage_value();
		player.debt+=chosen->get_mortgage_value();
		chosen->mortgaged=true;
	} else {
		std::cout<<"All of you properties are mortgaged! You need to sell something\n";
	}
	}
}

void Monopoly::show_stats(Player& player){
	std::cout<<"\nStats for "<<player.get_name()<<"\n";
	std::cout<<"Cash: $"<<player.cash<<"\n";
	std::cout<<"Debt: $"<<player.debt<<"\n";
	std::cout<<"Net worth: $"<<player.calc_net_worth(gb)<<"\n";
	std::cout<<"Title Deeds:\n";
	for (int x=0; x<player.num_properties_owned(); x++) {
		int p = player.get_property_owned(x);
		gb[p]->show_details();
	}
	if (player.has_get_out_of_jail_card()) {
		std::cout<<"Get out of jail card(s):\n";
		player.showJailCards();
	}
	std::cout<<"\n";
}
int Monopoly::show_options(Player& player) {
	int choice=10;
	std::string input="";
	while (choice<0 || choice >9){
		std::cout<<"What else do you want to do?\n";
		std::cout<<"0: Move on to the next player\n";
		std::cout<<"1: Show my stats\n";
		std::cout<<"2: Buy/sell a house\n";
		std::cout<<"3: Buy/sell a hotel\n";
		std::cout<<"4: Mortgage one of my properties\n";
		std::cout<<"5: Pay a mortgage\n";
		std::cout<<"6: Sell property to the bank\n";
		std::cout<<"7: Trade property and/or with another player\n";
		std::cout<<"8: Leave game\n";
		std::cout<<"9: End game\n";
		std::cin>>input;
		try {
			choice=stoi(input);
		} catch (...) {
			std::cout<<"Invalid input\n";
		}
	}
	return choice;
}

void Monopoly::players_turn (Player& player) {
	std::cout<<player.get_name()<<"'s turn!\n";
	std::string input;
	bool missed_turn=false;
	if (player.in_jail){
    	int choice=0;
    	std::cout<<"You are in jail. What do you want to do?\n";
    	while( !(choice==1 || choice==2 || choice==3 && player.has_get_out_of_jail_card()) ) {
			std::cout<<"1: Pay $500\n";
			std::cout<<"2: Miss turn\n";
			if (player.has_get_out_of_jail_card()){
				std::cout<<"3: Use get out of jail card\n";
			}
			std::cin>>input;
			try {
				choice = stoi(input);
			} catch (...) {
				std::cout<<"Invalid input\n";
			}
		}
		switch(choice){
			case 1:
				player.cash-=500;
				player.in_jail=false;
				std::cout<<"You paid $500. You now have $"<<player.cash<<".\n";
				break;
			case 2:
				std::cout<<"You missed your turn.\n";
				missed_turn=true;
				break;
			case 3:
				player.remove_jail_card();
				std::cout<<"You used your get out of jail card.\n";
				player.in_jail=false;
				break;
			default:
				std::cout<<"Invalid input\n";
				break;
		}
	}
	if (!player.in_jail){
    	int roll;
    	int doubles_count=0;
    	bool first_roll = true;
    	while(first_roll || (doubles_count>0 && !(player.in_jail))) {
			if (doubles_count>0) {
					std::cout<<player.get_name()<<" can roll again!\n";
			}
				gb.roll();
				roll = gb.getRoll();
				if (gb.isDoubles()) {
					std::cout<<"Doubles!\n";
					doubles_count++;
				}
				else {
					doubles_count=0;
				}
				if (doubles_count>2) {
					std::cout<<"You rolled doubles 3 times in a row!\n";
					std::cout<<"Go to jail!\n";
					player.in_jail=true;
					player.position=10;
				}
			else {
					player.move(roll);
					std::cout<<"You landed on "<<gb[player.position]->get_name()<<"\n";
					(gb[player.position])->action(player, gb,players);
					while (player.cash<0){
						std::cout<<"You need to take a mortgage to cover the debt\n";
						take_mortgage(player);
					}
			}
		first_roll = false;
    	}}
	if (missed_turn){
		player.in_jail=false;
	}
}

bool Monopoly::is_bankrupt(Player& player){
	int net_worth=player.calc_net_worth(gb);
	return net_worth<0;
}

std::string Monopoly::player_who_went_bankrupt(){
    for (int i=1; i<players.size(); i++){
	Player& player=players[i];
	if (is_bankrupt(player)){
		return player.get_name();
	}
    }
    return "";
}

bool Monopoly::endTurn(Player& player) {
	int input=10;
	if (!player.in_jail) {
		while (input!=0 && input!=9) {
			input=show_options(player);
			switch(input){
				case 0:
					break;
				case 1:
					show_stats(player);
					break;
				case 2:
					std::cout<<"Sorry this hasn't been set up yet\n";
					break;
				case 3: 
					std::cout<<"Sorry this hasn't been set up yet\n";
					break;
				case 4:
					take_mortgage(player);
					break;
				case 5:
					std::cout<<"Sorry this hasn't been set up yet\n";
					break;
				case 6:
					std::cout<<"Sorry this hasn't been set up yet\n";
					break;
				case 7:
					std::cout<<"Sorry this hasn't been set up yet\n";
					break;
				case 8:
					std::cout<<"Sorry this hasn't been set up yet\n";
					break;
				case 9:
					return false;
					break;
				default:
					std::cout<<"Invalid input\n";
					break;
			}
		}
		input=10;
	} else {
		std::string entered="";
		while (input!=0 && input !=1) {
			std::cout<<"Continue game?(y=1,n=0)\n";
			std::cin>>entered;
			try{
				input = stoi(entered);
			} catch (...) {
				std::cout<<"Invalid input\n";
			}
		}
		return input;
	}
	return true;
}

void Monopoly::mainGameLoop(){
    bool game = true;
    int input=10;
    while (game) {
		for (int i=1; i<players.size() && game; i++) {
			players_turn(players[i]);
			std::string loser=player_who_went_bankrupt();
			if (loser!=""){
				game=false;
				std::cout<<loser<<" went bankrupt!\n";
				break;
			}
			if (game) {
				game = endTurn(players[i]);
			}
		}
    }
}

void Monopoly::play() {
	assign_players();
	mainGameLoop();
	end_game();
}
