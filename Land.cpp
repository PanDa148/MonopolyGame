#include "Land.h"
#include "Player.h"
Land::Land(){}
Land::Land(std::string new_name, std::string new_color,int new_value,int new_base_rent_val, int new_rent_1h, int new_rent_2h, int new_rent_3h, int new_rent_4h, int new_rent_hotel)
    :Property(new_name, new_value, new_color),
    base_rent_val(new_base_rent_val),
    rent_1h(new_rent_1h),
    rent_2h(new_rent_2h),
    rent_3h(new_rent_3h),
    rent_4h(new_rent_4h),
    rent_hotel(new_rent_hotel)
    {}


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

int Land::total_val() {
    int total=value;
    for (int i=0;i<=num_houses; i++) {
        total+=get_house_val();
    }
    if (hotel) {
        value+=get_hotel_val();
    }
    return total;
}

int Land::rent(std::vector<Space*>& spaces, int dice_rolled) {
    int num=0;
    if (color=="blue" || color=="purple") {
        num = 2;
    }
    else {
        num=3;
    }
    int c = count(spaces);
    if (c != num){
	return base_rent_val;
    }
    else if (c == num && num_houses==0 && !hotel){
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
    else if (hotel) {
	return rent_hotel;
    }
    else {
	return 0;
    }
}
void Land::show_details(){
	Property::show_details();
    std::cout<<color<<"\n";
	std::cout<<"Rent $"<<base_rent_val<<"\n";
	std::cout<<"With 1 House $"<<rent_1h<<"\n";
	std::cout<<"With 2 Houses"<<rent_2h<<"\n";
	std::cout<<"With 3 Houses"<<rent_3h<<"\n";
	std::cout<<"With 4 Houses"<<rent_4h<<"\n";
	std::cout<<"With HOTEL $"<<rent_hotel<<"\n";
	std::cout<<"Mortgage Value $"<<value/2<<"\n";
	std::cout<<"Houses cost $"<<Land::get_house_val()<<" each\n";
	std::cout<<"Hotels cost $"<<Land::get_hotel_val()<<"each\n";
	std::cout<<"If a player owns ALL the lots of any color group, the rent is doubles on unimproved lotes in that group.\n\n";
}
