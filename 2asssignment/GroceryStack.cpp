#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "GroceryStack.h"
using namespace std;

GroceryStack::GroceryStack()
{
  bool tf;
  tf = isFile();
  if (tf)
  {
    getFile();
  }
  else
  {
    cout<<"Data File not found. Please label data file as ""history.dat"<<endl;
  }
}

bool GroceryStack::isFile()
{
  bool tf;
  string test;
  ifstream inputFile;
  inputFile.open("history.dat");
  if (inputFile)
  {
    tf = true;
    inputFile>>test;
    if (test == "")
    {
      tf = false;
    }
  }
  else
  {
    tf = false;
  }
  inputFile.close();
  return tf;
}

void GroceryStack::getFile()
{
  ifstream inputFile;
  string n;
  int v;
  float p;
  inputFile.open("history.dat");
  
  while (!inputFile.end)
  {
    getline(inputFile, n);
    inputFile>>v;
    inputFile>>p;
    pushFile(n,v,p);
  }
  return;
}

void GroceryStack::pushFile(string n, int v, float p)
{
   GStack *newNode = nullptr; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new GStack;
   newNode->product = n;
   newNode->value = v;
   newNode->price = p;
  

   // If there are no nodes in the list
   // make newNode the first node.
   if (!top)
   {
      top = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert NewNode before top.
   {
      newNode->next = top;
      top = newNode;
   }
}

void GroceryStack::printInfo(int x)const
{
  GStack *nodePtr;
  int counter;
  nodePtr = top;
  cout<<"Here are your recent products:"<<endl;
  while (nodePtr && counter <= x )
  {
    cout<<nodePtr->product<<"  ";
    cout<<nodePtr->value<<"  ";
    cout<<fixed<<setprecision(2)<<"$"<<nodePtr->price;
    counter++;
  }
  cout<<endl;
}
