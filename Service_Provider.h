#include "Property.h"
class Player;
class Service_Provider:public Property
{
public:
  Service_Provider ();
  Service_Provider (std::string new_name);
  void show_details();
  int rent(std::vector<Space*>& spaces, int dice_rolled);
};
