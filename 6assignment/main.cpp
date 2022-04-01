// CSC 300
// Bodie Bice

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <limits>
#include "HashPython.h"
using namespace std;

void menu(HashPython);

int main()
{
  HashPython lib;
  cout<<"Check";
  menu(lib);
}

void menu(HashPython lib)
{
  string file;
  string place;
  int count;
  char keepgoing;
  bool out = false;
  bool error;
  cin.clear();
  cout<<"Enter file name with terms: "<<endl;
  getline(cin,file);
  while (cin.fail() == true)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        getline(cin,file);
    }
  cout<<"check "<<file<<endl;
  ifstream inputFile;
  cout<<"check2"<<endl;
  while (out == false)
  {
    inputFile.open(file);
    while (!inputFile.eof())
    {
      getline(inputFile,place);
      if( inputFile.eof() ) break;
      error = lib.findWord(place);
      if (error == true)
      {
        cout<<place<<" was found in the table."<<endl;
      }
      place.clear();
      count++;
    }
    cout<<"The total number of words found in the file that match the index are "<<count<<endl;
    cout<<endl;
    lib.printHashTable();
    cout<<"Do you want to continue (1 for yes, anything else for no)"<<endl;
    cin.clear();
    cin>>keepgoing;
    while (cin.fail() == true)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin>>keepgoing;
    }
    if (keepgoing == '1')
    {
      cin.clear();
      cout<<"Enter file name with terms: "<<endl;
      getline(cin,file);
      ifstream inputFile;
      while (cin.fail() == true)
      {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        getline(cin,file);
      }
      count = 0;
    }
    else
    {
      out = true;
    }
  }
  return;
}