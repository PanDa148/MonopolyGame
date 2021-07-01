#include <iostream>
#include <cmath>
#include <algorithm>
#include "Monopoly.h"
//Compilation command: g++ -c -std=c++0x Monopoly.cpp
Monopoly::Monopoly(){}
Monopoly::~Monopoly(){
	players.clear();
    /*for (int x = 0; x<community_chest_cards.size(); x++) {
	delete community_chest_cards[x];
    }
    community_chest_cards.clear();
    for (int x = 0; x<chance_cards.size(); x++) {
	delete chance_cards[x];
    }
    chance_cards.clear();*/
}

void Monopoly::assign_players() {
    int num_players=0;
    Player null_player(" ");
    players.push_back(null_player);
    std::vector<std::string> mascots {"Dog","Ship","Coffee","Laptop","Shoe","McDonald's Cup","Airplane","Cellphone"};
    while(num_players<1 || num_players>8){
        std::cout<<"How many players?(1-8)\n";
        std::cin>>num_players;
    }
    int player_num=1;
    while (player_num<=num_players) {
        int choice;
        int input;
        std::cout<<"Which token does player "<<player_num<<" want to be?\n";
        for (int i=0; i<mascots.size(); i++) {
            std::cout<<i+1<<": "<<mascots[i]<<"\n";
        }
        std::cin>>input;
        choice = input-1;
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

void Monopoly::assemble_cards(){/*
	Card* aa = new Get_out_of_jail_free("Receive a presidential pardon");
	Card* ab = new Collect_from_each_player("You file as a candidate for Mayor.", 500);
	Card* ac = new Advance_to("Advance to \"GO\"", 0);
	community_chest_cards = {aa, ab, ac};
	Card* ba = new Advance_to("Bad weather forces your flight to get rerouted through Chicago. Advance to ORD Airport.", 5);
	Card* bb = new Advance_to("Celebrate New Year's Eve in The Big Apple. Advance to Times Square.", 38);
	Card* bc = new Advance_to(" ", "air");
	chance_cards = {ba, bb, bc};*/
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
	std::string input;
	std::cout<<"Which property do you want to mortgage?\n";
	std::vector<int> properties_to_mortgage;
	for (int x = 0; x<40; x++){
		Space* chosen = gb[x];
		if ((chosen->owner == player.get_name()) && !(chosen->mortgaged)){
			properties_to_mortgage.push_back(x);
		}
	}
	for (int x=0; x<properties_to_mortgage.size(); x++){
		int i = properties_to_mortgage[x];
		Space* p = gb[i];
		std::cout<<x<<": "<<p->get_name()<<" for $"<<p->get_mortgage_value()<<"\n";
	}
	std::cin>>input;
	int choice = stoi(input);
	Space* chosen = gb[properties_to_mortgage[choice]];
	player.cash+=chosen->get_mortgage_value();
	player.debt+=chosen->get_mortgage_value();
	chosen->mortgaged=true;
}

void Monopoly::show_properties_owned(Player& player){
	int num_properties_owned = player.num_properties_owned();
	std::cout<<"Which property do you want to see?\n";
	int input;
	for (int x=0; x<num_properties_owned; x++){
		std::cout<<x<<": "<<gb[player.get_property_owned(x)]->get_name()<<"\n";
	}
	std::cin>>input;
	Space* choice = gb[player.get_property_owned(input)];
	choice->show_details();
}
int Monopoly::show_options(Player& player) {
	int input;
	std::cout<<"What else do you want to do?\n";
	std::cout<<"0: Move on to the next player\n";
	std::cout<<"1: Show properties I own\n";
	std::cout<<"2: Buy/sell a house\n";
	std::cout<<"3: Buy/sell a hotel\n";
	std::cout<<"4: Mortgage one of my properties\n";
	std::cout<<"5: Pay a mortgage\n";
	std::cout<<"6: Sell property to the bank\n";
	std::cout<<"7: Trade property and/or with another player\n";
	std::cout<<"8: Leave game\n";
	std::cout<<"9: End game\n";
	std::cin>>input;
	return input;
}
int Monopoly::move_player(Player& player,int num){
    int old_pos = player.position;
    if ((old_pos+num)>39) {
	player.position=old_pos+num-40;
	std::cout<<"You passed GO!\n";
	player.cash+=2000;
    }
    else {
        player.position+=num;
    }
    int new_pos = player.position;
    std::cout<<"You landed on "<<gb[new_pos]->get_name()<<"\n";
    return new_pos;
}
void Monopoly::players_turn (Player& player) {
	std::cout<<player.get_name()<<"'s turn!\n";
	std::string input;
	bool missed_turn=false;
	if (player.in_jail){
    		int choice=0;
    		std::cout<<"You are in jail. What do you want to do?\n";
    		while((choice!=1 && choice !=2 && choice!=3) || (choice==3 && !player.get_out_of_jail_card) ){
			std::cout<<"1: Pay $500\n";
			std::cout<<"2: Miss turn\n";
			if (player.get_out_of_jail_card){
				std::cout<<"3: Use get out of jail card\n";
			}
			std::cin>>input;
			choice = stoi(input);
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
					if (player.get_out_of_jail_card){
						std::cout<<"You used your get out of jail card.\n";
						player.in_jail=false;
					}
					else{
						std::cout<<"Invalid input\n";
					}
					break;
				default:
					std::cout<<"Invalid input\n";
					break;
			}
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
	    		int new_pos = Monopoly::move_player(player,roll);
   	    		(gb[new_pos])->action(player, gb,players);
    			std::cout<<"You have $"<<player.cash<<".\n";
    			while (player.cash<0){
				std::cout<<"You need to take a mortgage to cover the debt\n";
				Monopoly::take_mortgage(player);
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
	if (Monopoly::is_bankrupt(player)){
		return player.get_name();
	}
    }
    return " ";
}

void Monopoly::manage_player_turns(){
    bool game = true;
    int input=10;
    while (game) {
		for (int i=1; i<players.size() && game; i++) {
			Monopoly::players_turn(players[i]);
			std::string loser=Monopoly::player_who_went_bankrupt();
			if (loser!=" "){
			game=false;
			std::cout<<loser<<" went bankrupt!\n";
			break;
			}
			if (!players[i].in_jail) {
				while (input!=0 && input!=9) {
					input=Monopoly::show_options(players[i]);
					switch(input){
						case 0:
							break;
						case 1:
							for (int x=0; x<players[i].num_properties_owned(); x++) {
								int p = players[i].get_property_owned(x);
								gb[p]->show_details();
							}
							break;
						case 2:
							std::cout<<"Sorry this hasn't been set up yet\n";
							break;
						case 3: 
							std::cout<<"Sorry this hasn't been set up yet\n";
							break;
						case 4:
							Monopoly::take_mortgage(players[i]);
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
							game=false;
							break;
						default:
							std::cout<<"Invalid input\n";
							break;
					}
				}
				input=10;
			} else {
				while (input!=0 && input !=1) {
					std::cout<<"Continue game?(y=1,n=0)\n";
					std::cin>>input;
				}
				game=input;
			}
		}
    }
}
