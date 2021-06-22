#include <iostream>
#include "Dice.h"
#include <stdlib.h>
#include <string>
#include <vector>

Dice::Dice()
    :die1(0)
    ,die2(0)
{}
    
int Dice::get_roll() {
    return die1+die2;
}
bool Dice::is_doubles() {
    return die1==die2;
}

void Dice::roll() {
std::string input;
  std::string::iterator letter;
  int length;
  std::vector<int> nums;
  int sum=0;
  int pos1;
  int pos2;
      std::cout << "Press a bunch of random keys to roll\n";
      std::cin >> input;
      length = input.length ();
      while (length<20) {
          std::cout<<"Please enter an input of at least 20 characters\n";
          std::cin >> input;
          length = input.length ();
      }
      for (letter=input.begin(); letter!=input.end(); letter++) 
        {
          nums.push_back( (int) (*letter) );
          //std::cout<<(int) (*letter)<<" ";
        }
        //std::cout<<"\n";
      for (int x=0; x<nums.size(); x++) {
          int& num = nums[x];
          while (num>20) {
              num = num/2;
          }
          //std::cout<<num<<" ";
      }
        //std::cout<<"\n";
        pos1 = nums[nums.size()/3]-1;
        pos2 = nums[2*nums.size()/3]-1;
        for (int i=0; i<nums.size(); i++){
            int& num = nums[i];
            while (num>6){
                num=num/2;
            }
            //std::cout<<num<<" ";
        }
        //std::cout<<"\n";
        die1 = nums[pos1];
        die2 = nums[pos2];
        //std::cout<<pos1<<" "<<pos2<<"\n"<<roll1<<" "<<roll2<<"\n"<<roll1+roll2<<"\n";
        //std::cout<<"You rolled: "<<roll1+roll2<<"\n";
}
