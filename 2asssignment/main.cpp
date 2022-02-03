#include <string>
#include <iostream>
#include <fstream>
#include "GroceryStack.h"
using namespace std;

//void menu(GroceryStack *);


int main()
{
	bool tf;
	GroceryStack x;
	tf = x.isFile();
	x.getFile();
	x.printInfo(3);
	return 0;
}