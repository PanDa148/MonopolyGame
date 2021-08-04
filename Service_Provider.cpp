#include <iostream>
#include "Service_Provider.h"
Service_Provider::Service_Provider(){}
Service_Provider::Service_Provider(std::string new_name)
    :Property(new_name+" Service Provider", 1500, "sp")
    {}

int Service_Provider::rent(GameBoard& gb) {
    int roll=gb.getRoll();
    switch(count(gb)){
        case 1:
            return 40*roll;
            break;
        case 2:
            return 100*roll;
            break;
        default:
            return 0;
    }
}

void Service_Provider::show_details(){
	Property::show_details();
	std::cout<<"If one \"Service Provider\" is owned, rent is 40 times amount shown on dice.\n";
	std::cout<<"If both \"Serivce Providers\" are owned, rent is 100 times amount shown on dice.\n";
	std::cout<<"Mortgage value	$750\n\n";
}