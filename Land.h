#pragma once
#include "Property.h"

class Land : public Property
{
  int rentVals [6];

public:
  Land ();
  Land(std::string new_name, std::string new_color,int value, int base_rent, int rent1, int rent2, int rent3, int rent4, int rentH);
  int total_val();
  void show_details();
  int get_house_val ();
  int get_hotel_val ();
  int rent(GameBoard& gb);
  //std::string CSVstring();
};
