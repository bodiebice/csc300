#ifndef GroceryStack_h
#define GroceryStack_h
#include <string>
#include <fstream>
using std::string;

class GroceryStack
{
private:
    struct GStack
    {
        string product;
        int value;
        float price;
        GStack* next;
    };
    GStack* top;

    
    void pushFile(string n, int v, float p);

public:
    GroceryStack();
    bool isFile();
    void getFile();
    void printInfo(int x)const;
    //int  printSum()const;


};
#endif