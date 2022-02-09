// Bodie Bice
// CSC 300

#ifndef StaticQueue_h
#define StaticQueue_h
#include <string>
using std::string;

class StaticQueue
{
  private:
    struct PatientInfo
    {
      string name;
      int age;
      string problem;
    };
    PatientInfo *array;
    int queueSize;
    int front;
    int rear;
    int numStruc;
    
  public:
    StaticQueue(int);
    StaticQueue(StaticQueue &);
    bool isFull();
    bool isEmpty();
    bool enqueue(string, int, string);
    bool dequeue (string &, int &, string &);
};
#endif