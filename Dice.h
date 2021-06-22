#pragma once

class Dice
{
  int die1;
  int die2;

public:
    Dice ();
    int get_roll ();
    bool is_doubles();
    void roll ();
};
