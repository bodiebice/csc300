// Bodie Bice
// CSC 300

#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
using namespace std;

void BST::setBranch(treeNode *&  nodePtr, treeNode *&newNode)
{
  if (nodePtr == nullptr)
    nodePtr = newNode;
  else if (newNode->title.compare(0,string::npos,nodePtr->title)<0)
    setBranch(nodePtr->left, newNode);
  else 
    setBranch(nodePtr->right, newNode);
}

void BST::insertBranch(string t, int v, int l)
{
  treeNode *newNode = nullptr;
  newNode = new treeNode;
  newNode->title = t;
  newNode->likes = l;
  newNode->views = v;

  setBranch(root, newNode);
}

bool BST::isFile()
{
  bool tf;
  string test;
  ifstream inputFile;
  inputFile.open(filename);
  if (inputFile)
  {
    tf = true;
    getline(inputFile, test);
    if (test == "")
      tf = false;
    
  }
  else
    tf = false;
  inputFile.close();
  return tf;
}
void BST::getFile()
{
  fstream inputFile;
  inputFile.open(filename);
  while (!inputFile.fail())
  {
    string t;
    int v, l = 0;
    inputFile>>l>>v;
    getline(inputFile, t);
    if (!t.empty())
    {
      insertBranch(t,v,l);
    }
    inputFile.ignore();
  }
  inputFile.close();
  return;
}
void BST::destroySubTree(treeNode *nodePtr)
{
  if(nodePtr)
  {
    if (nodePtr->left)
      destroySubTree(nodePtr->left);
    if (nodePtr->right)
      destroySubTree(nodePtr->right);
    delete nodePtr;
  }
}

void BST::remove(string t)
{
  deleteNode(t, root);
}

void BST::deleteNode(string t, treeNode *&nodePtr)
{
  if (t.compare(0,string::npos,nodePtr->title) <0)
    deleteNode(t,nodePtr->left);
  else if (t.compare(0,string::npos,nodePtr->title)>0)
    deleteNode(t, nodePtr->right);
  else
    makeDeletion(nodePtr);
}

