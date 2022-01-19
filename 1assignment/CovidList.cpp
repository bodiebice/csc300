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
  newNode->covidnow = 0;
  newNode->covidrecov = 0;
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
  cout<<endl;
}

void CovidList::addCovid(string n, int a)
{
  listNode *nodePtr;
  listNode *previousNode;

  if(!head)
    return;
  if (head->name == n)
  {
    head->covidnow = head->covidnow+a;
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
      nodePtr->covidnow = nodePtr->covidnow+a;
    }
  }
}

void CovidList::recovCovid(string n, int c)
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
      nodePtr->covidnow = nodePtr->covidnow - c;
      nodePtr->covidrecov= nodePtr->covidrecov+c;
    }
  }
}

void CovidList::printInfo()const
{
  listNode *nodePtr;
  nodePtr = head;
  cout<<"Here are all classes and the data in each one:"<<endl;
  cout<<"Class name      Class Number     # of Students in Class   # of students with covid    # of students recovered from covid"<<endl;
  while (nodePtr)
  {
    cout<<nodePtr->name<<"     ";
    cout<<nodePtr->section<<"     ";
    cout<<nodePtr->students<<"   ";
    cout<<nodePtr->covidnow<<"   ";
    cout<<nodePtr->covidrecov<<endl;
    nodePtr = nodePtr->next;
  }
  cout<<endl;
}
