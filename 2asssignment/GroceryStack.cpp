#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "GroceryStack.h"
using namespace std;

GroceryStack::GroceryStack()
{
    top = nullptr;
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
        inputFile >> test;
        if (test == "")
        {
            tf = false;
        }
    }
    else
    {
        cout << "No File Detected" << endl;
        tf = false;
    }
    inputFile.close();
    return tf;
}

void GroceryStack::getFile()
{
    ifstream inputFile;
    
    inputFile.open("history.dat");

    while (!inputFile.fail())
    {
      string n;
      int v = 0;
      float p = 0;;
      getline(inputFile, n);
      inputFile>>v>>p;
      cout<<n<<" "<<v<<" "<<p<<endl;
      cout<<n<<endl;
      pushFile(n,v,p);
      inputFile.ignore();
    }
    return;
}

void GroceryStack::pushFile(string n, int v, float p)
{
    GStack* newNode = nullptr; // Pointer to a new node

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
    GStack* nodePtr;
    nodePtr = top;
    int xy = 0;
    cout << "Here are your recent products:" << endl;
    while (nodePtr && xy <= x)
    {
        cout << nodePtr->product << "  ";
        cout << nodePtr->value << "  ";
        cout << fixed << setprecision(2) << "$" << nodePtr->price;
        xy++;
        nodePtr = nodePtr->next;
    }
    cout << endl;
}