#include <iostream>
#include <iomanip>
#include <string>
#include "CovidList.h"
using namespace std;

CovidList::CovidList()
{
  head = nullptr;
}

void CovidList::addClass(string n, int c, int s)
{
  listNode *newNode;
  listNode *nodePtr;
  listNode *previousNode = nullptr;

  newNode = new listNode;
  newNode->name = n;
  newNode->section = c;
  newNode->students = s;

  if (!head)
  {
    head = newNode;
    newNode->next = nullptr;
  }
  else
  {
    nodePtr = head;
    previousNode = nullptr;
    while (nodePtr != nullptr && newNode->name.compare(0, 1, nodePtr->name)!=0 && newNode->name.compare(0, 1, nodePtr->name)>0)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }
    if (previousNode == nullptr)
    {
      head = newNode;
      newNode->next = nodePtr;
    }
    else
    {
      previousNode->next = newNode;
      newNode->next = nodePtr;
    }
  }
}

void CovidList::addCovid(string n, int a)
{
  listNode *nodePtr;
  listNode *previousNode;

  if(!head)
    return;
  if (head->name == n)
  {
    nodePtr = head->next;
    delete head;
    head = nodePtr;
  }
  else
  {
    nodePtr = head;
    
    while (nodePtr != nullptr && nodePtr->name != n)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }
    if (nodePtr)
    {
      nodePtr->covidnow = a;
    }
  }
}

void CovidList::recovCovid(string n)
{
  listNode *nodePtr;
  listNode *previousNode;

  if(!head)
    return;
  if (head->name == n)
  {
    nodePtr = head->next;
    delete head;
    head = nodePtr;
  }
  else
  {
    nodePtr = head;
    
    while (nodePtr != nullptr && nodePtr->name != n)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }
    if (nodePtr)
    {
      nodePtr->covidnow = nodePtr->covidnow - 1;
      nodePtr->covidrecov++;
    }
  }
}

void CovidList::printInfo()const
{
  listNode *nodePtr;
  nodePtr = head;
  cout<<"Here are all classes and the data in each one:"<<endl;
  while (nodePtr)
  {
    cout<<"Class Name: "
    cout<<nodePtr->name<<;
    cout<<
    nodePtr = nodePtr->next;
  }
}
