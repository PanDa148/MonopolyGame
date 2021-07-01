#include "Property.h"
#include <iostream>
Airport::Airport(){}
Airport::Airport(std::string new_name)
    :Property(new_name+" Airport", 2000, "air")
    {}

int Airport::rent(GameBoard& gb) {
    switch(count(gb)){
        case 1:
            return 250;
            break;
        case 2:
            return 500;
            break;
        case 3:
            return 1000;
            break;
        case 4:
            return 2000;
            break;
	default:
	    return 0;
    }
}

void Airport::show_details(){
	Property::show_details();
	std::cout<<"Rent			$250\n";
	std::cout<<"If 2 Airports are owned      500\n";
	std::cout<<"If 3     \"     \"    \"       1000\n";
	std::cout<<"If 4     \"     \"    \"       2000\n";
	std::cout<<"Mortgage value            $1000\n\n";
}
