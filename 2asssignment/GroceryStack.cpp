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
// isFile is a function that tests for if the file exists.
bool GroceryStack::isFile()
{
    bool tf;
    string test;
    ifstream inputFile;
    inputFile.open("history.dat");
    // the if/else statement below simply checks to see if inputFile exists.
    if (inputFile)
    {
      //set the flag returned to true
        tf = true;
        inputFile >> test;
        if (test == "")
        {
            tf = false;
        }
    }
    else
    {
      //set the flag to false.
        tf = false;
    }
    inputFile.close();
    return tf;
}
// this function will get all data from the file and suck them into the linked list as indivudial nodes.
void GroceryStack::getFile()
{
    ifstream inputFile;
    
    inputFile.open("history.dat");
    //while the program is open and isn't at the end.
    while (!inputFile.fail())
    {
      string n;
      int v = 0;
      float p = 0;;
      getline(inputFile, n);
      inputFile>>v>>p;
      //cout<<n<<" "<<v<<" "<<p<<endl;
      //cout<<n<<endl;

      // I ran into a really weird bug where the end white space in my data file would get sucked in as a fourth data member. 
      // I remedied this by seeing if the string was empty/white space before sending the data to the function to make the node.

      if (!n.empty())
      {
        pushFile(n,v,p);
      }
      //
      inputFile.ignore();
    }
    // good stewards of data always close files :)
    inputFile.close();
    return;
}
//this function will push a new node (GStack) to the linked list.
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
// this function will print historical data from the top of the stack for the user.
void GroceryStack::printInfo(int x)const
{

    GStack* nodePtr;
    nodePtr = top;
    // xy is a counter to be compared against x, which is what the user says how many items they want to see.
    int xy = 0;
    cout << "Here are your recent products:" << endl;
    //while there are nodes ahead and xy is less than x.
    while (nodePtr && xy < x)
    {
        cout << "Product: "<<nodePtr->product << "  ";
        cout << "Qty Purchased: "<<nodePtr->value << "  ";
        cout << "Price: "<<fixed << setprecision(2) << "$" << nodePtr->price<<endl;
        xy++;
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
//this function will add up recursively the total price spent on each product (aka the volume bought multiplied by the price (value and price)
float GroceryStack::printSum()const
{
  float total = 0;
  return countSum(top,total);

}

float GroceryStack::countSum(GStack* nodePtr, float total)const
{

  if (nodePtr!=nullptr)
  {
    //make the total that adds to the other ones the price multiplied by the quantity.
    total = (nodePtr->price*nodePtr->value);
    return total+countSum(nodePtr->next,total);
  }
  //if there's no more nodes, return and stop the recursive call.
  else
  {
    return 0;
  }
}
