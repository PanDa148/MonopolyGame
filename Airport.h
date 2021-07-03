#pragma once
#include "Property.h"
class Player;

class Airport : public Property
{
public:
  Airport ();
  Airport (std::string new_name);
  void show_details();
  int rent(std::vector<Space*>& spaces, int dice_rolled);
};
