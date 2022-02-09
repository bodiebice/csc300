// Bodie Bice
// CSC 300
#include <iostream>
#include <string>
#include "StaticQueue.h"
using namespace std;

StaticQueue::StaticQueue(int a)
{
  array = new PatientInfo[a];
  queueSize = a;
  front = -1;
  rear = -1;
  numStruc = 0;
}

StaticQueue::StaticQueue(StaticQueue & obj)
{
  array = new PatientInfo[obj.queueSize];
  front = obj.front;
  rear = obj.rear;
  numStruc=obj.numStruc;

  for (int count = 0; count < obj.queueSize; count++)
  {
    array[count].name = obj.array[count].name;

}