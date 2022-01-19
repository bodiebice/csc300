#include <iostream>
#include <string>
#include <limits>
#include "CovidList.h"
using namespace std;

void toMenu(CovidList*);
void addClass(CovidList*, string[99]);
void increaseCovid(CovidList*, string[99]);
void decreaseCovid(CovidList*, string[99]);
void printList(CovidList*);

//main's only goal is to initialize the object and send the program to the menu function.
int main()
{
  CovidList* registar;
  registar = new CovidList;
  toMenu(registar);
  return 0;
}
// the menu functions to direct the user between the four different things that the user can have the program do
void toMenu(CovidList* registar)
{
  string n[99];
  bool done = false;
  int choice;
  while (done == false)
  {
    cout<<"Welcome to your personal Class COVID-19 Registar. Press 1 to enter a new class, 2 to report students with covid, or 3 to report students who have recovered."<<endl<<"Press 4 to display all information. Press any other number to exit."<<endl;
    cin>>choice;
    while (cin.fail() == true)
      {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin>>choice;
      }
      // i like using switch case statements for menus, makes things cleaner than if/elseif statements in my opinion.
    switch (choice)
    {
      case 1: addClass(registar,n);
        break;
      case 2: increaseCovid(registar,n);
        break;
      case 3: decreaseCovid(registar,n);
        break;
      case 4: printList(registar);
        break;    
      default: done = true;
        break;
    }
  }
}
//this is the add class function. it asks the user for the three varaibles needed and sends them to the object to be made into a node.
void addClass(CovidList* registar, string n[99])
{
  string place1;
  int place2, place3;
  int num = 0;
  cout<<endl<<"Class Title: ";
  cin.ignore(std::numeric_limits<int>::max(),'\n');
  getline(cin,place1);
  while (cin.fail() == true)
      {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        getline(cin,place1);
      }
  cout<<"Class Number: ";
  cin>>place2;
  while (cin.fail() == true)
      {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin>>place2;
      }
  cout<<"Number of Students: ";
  cin>>place3;
  while (cin.fail() == true)
      {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin>>place3;
      }
  registar->addClass(place1,place2,place3);
  while (!n[num].empty())
  {
    num++;
  }
  n[num] = place1;
  return;
}

void increaseCovid(CovidList* registar, string n[99])
{
  int num = 1,covid,pog;
  string place1;
  cout<<"Pick a Class to report students with COVID-19. Use the number next to the class name to pick."<<endl;
  while (!n[num-1].empty())
  {
    cout<<num<<" "<<n[num-1]<<endl;
    num++;
  }
  cin>>pog;
  place1 = n[pog-1];
  cout<<"How many students have covid in "<<n[pog-1]<<"?"<<endl;
  cin>>covid;
  registar->addCovid(place1,covid);
  cout<<endl;
  return;
}

void decreaseCovid(CovidList* registar, string n[99])
{
  string place1;
  int num=1,pog,covid;
  cout<<"Pick a class to report students who have recovered from COVID-19. Use the number next to the class name to pick."<<endl;
  while (!n[num-1].empty())
  {
    cout<<num<<" "<<n[num-1]<<endl;
    num++;
  }
  cin>>pog;
  place1 = n[pog-1];
  cout<<"How many students have recovered from COVID-19 in this class?"<<endl;
  cin>>covid;
  registar->recovCovid(place1,covid);
  return;
  cout<<endl;
}

void printList(CovidList* registar)
{
  registar->printInfo();
  return;
}

