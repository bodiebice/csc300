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

    float countSum(GStack*,float)const;
    void pushFile(string, int, float);

public:
    GroceryStack();
    bool isFile();
    void getFile();
    void printInfo(int)const;
    float printSum()const;


};
#endif