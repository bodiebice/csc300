#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include "GroceryStack.h"
using namespace std;

void menu(GroceryStack *);
void o1(GroceryStack *);

//main is used for initializing the grocerystack and ensuring that history.dat exists. once that is for sure a thing that exists, the program calls the menu.
int main()
{
	bool tf = false;
	GroceryStack* x;
  x = new GroceryStack;
	tf = x->isFile();
  if (tf)
  {
    x->getFile();
    menu(x);
  }
  else
  {
    cout<<"Error: No File Detected or No Text Detected in File. Please make sure your file is labeled history.dat"<<endl;
  }
	return 0;
}
//the menu drives user input to functions in the Class.
void menu(GroceryStack* x)
{
  bool out = true;
  char choice;
  float o2;
  while (out == true)
  {
    cout<<"Choose a Choice from the options below"<<endl;
    cout<<"1: Print Last Few Items"<<endl;
    cout<<"2: Find Total price for purchases"<<endl;
    cout<<"Press any key to exit."<<endl;
    // i decided a character instead of a int because it's easier to press any key on a keyboard to exit than simply any number but 1/2.
    cin>>choice;
    while (cin.fail() == true)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin>>choice;
    }
    
    if (choice == '1')
    {
      o1(x);
    }
    else if (choice == '2')
    {
      o2=x->printSum();
      cout<<"The total you've spent is $"<<fixed<<setprecision(2)<<o2<<endl;
    }
    else
    {
      out = false;
      
    }
  }
  return;
}

void o1(GroceryStack* x)
{
  int items;
  cout<<"How many items would you like to see from your shopping history? "<<endl;
  cin>> items;
  while (cin.fail() == true)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin>>items;;
    }
  x->printInfo(items);
}
