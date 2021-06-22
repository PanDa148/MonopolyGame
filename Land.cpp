#include "Land.h"
#include "Player.h"
Land::Land(){}
Land::Land(std::string new_name, int new_position,std::string new_color,int new_value,int new_base_rent_val, int new_rent_1h, int new_rent_2h, int new_rent_3h, int new_rent_4h, int new_rent_hotel)
    :Property(new_name, new_position),
    value(new_value),
    color(new_color),
    base_rent_val(new_base_rent_val),
    rent_1h(new_rent_1h),
    rent_2h(new_rent_2h),
    rent_3h(new_rent_3h),
    rent_4h(new_rent_4h),
    rent_hotel(new_rent_hotel),
    num_houses(0),
    num_hotels(0){}
    
int Land::get_value() {
    return value;
}

void Land::set_value(int new_value) {
    value = new_value;
}

int Land::get_mortgage_value() {
    return value/2;
}
    
std::string Land::get_color() {
    return color;
}

int Land::get_num_houses() {
    return num_houses;
}

int Land::get_num_hotels() {
    return num_hotels;
}

int Land::get_house_val() {
    if (color=="purple"||color=="light blue") {
        return 500;
    }
    else if (color=="orange"||color=="pink") {
        return 1000;
    }
    else if (color=="red"||color=="yellow") {
        return 1500;
    }
    else if (color=="green"||color=="blue") {
        return 2000;
    }
    else {
        std::cout<<"Oops! Something went wrong :(\n";
	return 0;
    }
}

int Land::get_hotel_val() {
    return Land::get_house_val()*5;
}

void Land::add_houses(int num) {
    num_houses = num_houses + num;
    Land::set_value(value+num*Land::get_house_val());
}

void Land::add_hotels(int num) {
    num_hotels = num_hotels + num;
    Land::set_value(value + num*Land::get_hotel_val());
}

int Land::determine_rent(std::vector<Space*>& spaces_ref) {//ends @ line 282 
    int num=0;
    if (color=="blue" || color=="purple") {
        num = 2;
    }
    else {
        num=3;
    }
    int c=0;
    for (int x=0; x<spaces_ref.size(); x++) {
        if (spaces_ref[x]->get_color()==color && spaces_ref[x]->get_owner()==owner_name) {
            c++;
        }
    }
    if (c != num){
	return base_rent_val;
    }
    else if (c == num && num_houses==0 && num_hotels==0){
	return base_rent_val*2;
    }
    else if (num_houses==1) {
	return rent_1h;
    }
    else if (num_houses==2) {
	return rent_2h;
    }
    else if (num_houses==3) {
	return rent_3h;
    }
    else if (num_houses==4) {
	return rent_4h;
    }
    else if (num_hotels==1) {
	return rent_hotel;
    }
    else {
	return 0;
    }
}
void Land::action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
	std::string input=" ";
	int rent = 0;
	while(input!="y" && input!="n" && input!="rent"){
		if (owner_name == "no one"){
			std::cout<<name<<" is not owned. Would you like to buy it for $"<<Land::get_value()<<"?(y/n)\n";
			std::cin>>input;
		}
		else if (owner_name == player.get_name()){
			std::cout<<"You own "<<name<<".\n";
			input="n";
		}
		else if (mortgaged) {
			std::cout<<name<<" is mortgaged.\n";
			input="n";
		}
		else {
			rent = Land::determine_rent(spaces_ref);
			std::cout<<name<<" is owned by "<<owner_name<<". Rent is $"<<rent<<".\n";
			input="rent";
		}
	}
	if (input=="y"){
		Land::set_owner(player.get_name());
		player.add_cash(-Land::get_value());
		player.add_property(position);
	}
	if (input=="rent"){
		player.add_cash(-rent);
		for (int x = 0; x<players_ref.size(); x++){
			if (players_ref[x].get_name()==owner_name){
				
				players_ref[x].add_cash(rent);
				break;
			}
		}
		std::cout<<"Rent paid to "<<owner_name<<"\n";
	}
}
void Land::show_details(){
	std::cout<<"\n"<<name<<" ("<<color<<")\n";
	if (mortgaged){
		std::cout<<"MORTGAGED\n";
	}
	std::cout<<"Rent $"<<base_rent_val<<"\n";
	std::cout<<"WIth 1 House $"<<rent_1h<<"\n";
	std::cout<<"WIth 2 Houses"<<rent_2h<<"\n";
	std::cout<<"WIth 3 Houses"<<rent_3h<<"\n";
	std::cout<<"WIth 4 Houses"<<rent_4h<<"\n";
	std::cout<<"With HOTEL $"<<rent_hotel<<"\n";
	std::cout<<"Mortgage Value $"<<value/2<<"\n";
	std::cout<<"Houses cost $"<<Land::get_house_val()<<" each\n";
	std::cout<<"Hotels cost $"<<Land::get_hotel_val()<<"each\n";
	std::cout<<"If a player owns ALL the lots of any color group, the rent is doubles on unimproved lotes in that group.\n\n";
}

        /*std::cin>>input;
        if (input=="y"||input=="Y"||input=="yes"||input=="Yes") {
            player.buy_sell_property()
        }*/

