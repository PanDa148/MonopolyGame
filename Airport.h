#pragma once
#include "Property.h"

class Airport : public Property
{
public:
  Airport ();
  Airport (std::string new_name);
  void show_details();
  int rent(GameBoard& gb);
};