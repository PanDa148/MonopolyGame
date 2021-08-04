#pragma once
#include "Property.h"

class Service_Provider:public Property
{
public:
  Service_Provider ();
  Service_Provider (std::string new_name);
  void show_details();
  int rent(GameBoard& gb);
};