#pragma once
#include <vector>
class Dice
{
  private:
  int die1;
  int die2;
  int i=0;
  std::vector<int> jail = {1,1,2,2,3,3,1,2,3,4,5,6};
  std::vector<int> airport = {2,3,2,3,4,6,4,6,6,4,4,6,4,6,4,6};
  std::vector<int> cards = {1,1,1,2,4,3,6,6,3,1,5,6,6,4,2,1,2,1};
  //player 1: 33
  //player 2: 21
  void normal();
  void test(std::vector<int> rolls);

  public:
  Dice();
  int get_roll ();
  bool is_doubles();
  void roll ();
};