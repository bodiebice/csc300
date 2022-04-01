// Bodie Bice
// CSC 300

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "HashPython.h"
using namespace std;

HashPython::HashPython()
{
  cout<<"Check";
  clearCounts();
  filename = "keywords.txt";
  ifstream inputFile;
  inputFile.open(filename);
  if (inputFile)
  {
    cout<<"yes"<<endl;
  }
  string temp;
  int index;
  int quadraticprobe = 1;
  bool fail;
  fail = false;
  for (int i = 0; i<=TABLE_SIZE; i++)
  {
    getline(inputFile, temp);
    index = hashkey(temp);
    if (hashTable[index].full == false)
    {
      hashTable[index].element = temp;
      hashTable[index].full = true;
    }
    else
    {
      fail = false;
      while (fail == false)
      {
        index = (index + pow(quadraticprobe,2));
        index = index % TABLE_SIZE;
        if (hashTable[index].full == true)
        {
          quadraticprobe++;
          fail = false;
        }
        else
        {
          hashTable[index].element = temp;
          hashTable[index].full = true;
          quadraticprobe++;
          fail = true;
        }
      }  
    }
  }
}

int HashPython::hashkey(const string indicator)
{
  unsigned int hashval = 0;
  hashval = indicator.front() + indicator.back();
  return hashval % TABLE_SIZE;
}

bool HashPython::findWord(const string indicator)
{
  int index;
  int quadprobe;
  bool re;
  index = hashkey(indicator);
  if (hashTable[index].element == indicator)
  {
    re = true;
    hashTable[index].count++;
  }
  else
  {
    while (hashTable[index].element != indicator || hashTable[(index + (quadprobe*quadprobe)) % TABLE_SIZE].full == false)
    {
      quadprobe++;
    }
    if (hashTable[(index + (quadprobe*quadprobe)) % TABLE_SIZE].element == indicator)
    {
      re = true;
      hashTable[(index + (quadprobe*quadprobe)) % TABLE_SIZE].count++;
    }
    else if (hashTable[(index + (quadprobe*quadprobe)) % TABLE_SIZE].full == true)
    {
      re = false;
    }
  }
  return re;
}

void HashPython::printHashTable() const
{
  int count;
  int space;
  for (count = 0; count <= TABLE_SIZE; count++)
  {
    cout<<"Table Element: "<<hashTable[count].element;
    space = 10 - hashTable[count].element.length();
    for (int x = 0; x<=space; x++)
    {
      cout<<" ";
    }
    cout<<"Times Searched: "<<hashTable[count].count<<endl;
  }
  return;
}

void HashPython::clearCounts()
{
  int count;
  cout<<"Check";
  for (count = 0; count <= TABLE_SIZE; count++)
  {
    hashTable[count].count = 0;
    hashTable[count].element.clear();
    hashTable[count].full = false;
  }
  return;
}