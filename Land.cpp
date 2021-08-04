#include "Land.h"
Land::Land(){}
Land::Land(std::string new_name, std::string new_color,int value, int base_rent, int rent1, int rent2, int rent3, int rent4, int rentH)
    : Property(new_name, value, new_color)
{
    rentVals[0]=base_rent;
    rentVals[1]=rent1;
    rentVals[2]=rent2;
    rentVals[3]=rent3;
    rentVals[4]=rent4;
    rentVals[5]=rentH;
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
        std::cout<<"Oops! Something went wrong in int Land::get_house_val() in Land.cpp at line 12 :(\n";
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

int Land::rent(GameBoard& gb) {
    int num=0;
    if (color=="blue" || color=="purple") {
        num = 2;
    }
    else {
        num=3;
    }
    int c = count(gb);
    if (c != num){
	    return rentVals[0];
    }
    else if (c == num && num_houses==0 && !hotel){
	    return rentVals[0]*2;
    }
    else if (num_houses>=1 && num_houses<=4) {
	    return rentVals[num_houses];
    }
    else if (hotel) {
	    return rentVals[5];
    }
    else {
	    return 0;
    }
}
void Land::show_details(){
	Property::show_details();
    std::cout<<color<<"\n";
	std::cout<<"Rent $"<<rentVals[0]<<"\n";
	std::cout<<"With 1 House $"<<rentVals[1]<<"\n";
	std::cout<<"With 2 Houses $"<<rentVals[2]<<"\n";
	std::cout<<"With 3 Houses $"<<rentVals[3]<<"\n";
	std::cout<<"With 4 Houses $"<<rentVals[4]<<"\n";
	std::cout<<"With HOTEL $"<<rentVals[5]<<"\n";
	std::cout<<"Mortgage Value $"<<value/2<<"\n";
	std::cout<<"Houses cost $"<<Land::get_house_val()<<" each\n";
	std::cout<<"Hotels cost $"<<Land::get_hotel_val()<<" each\n";
	std::cout<<"If a player owns ALL the lots of any color group, the rent is doubles on unimproved lots in that group.\n\n";
}

/*std::string Land::CSVstring() {
	return Property::CSVstring() + color + "$" + rentVals[0] + "$" + rentVals[1] + "$" + rentVals[2] + "$" + rentVals[3] + "$" + rentVals[4] + "$" + rentVals[5];
}*/
