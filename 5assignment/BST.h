// Bodie Bice
// CSC 300

#ifndef BST_h
#define BST_h
#include <string>
using std::string;

class BST
{
  private:
    struct treeNode
    {
      string title;
      int likes;
      int views;
      treeNode *left;
      treeNode *right;
    };
    treeNode *root;
    string filename;

    void setBranch(treeNode *&,treeNode *& );
    void destroySubTree(treeNode *);
    void deleteNode(string, treeNode *&);
    void makeDeletion(treeNode *&);
    void displayInOrder(treeNode *) const;
    int rootviewsAdd(treeNode *);
    int rootlikesAdd(treeNode *);
    void insertBranch(string, int, int);

  public:
    BST(string fname)
      {
        root = nullptr;
        filename = fname;
      };
    
    ~BST()
      { destroySubTree(root);}
    
    
    bool isFile();
    void getFile();
    bool searchBranch(string);
    void remove(string);

    void displayAlphabetically() const
      { displayInOrder(root);}

    void giveLikeView(int &, int &); 
};
#endif