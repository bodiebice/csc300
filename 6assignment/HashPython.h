// Bodie Bice
// CSC 300

#ifndef hashpython_h
#define hashpython_h
#include <string>
using std::string;

class HashPython
{
  private:
    enum TableLimit { TABLE_SIZE = 41};
    struct TableElem
    {
      bool full;
      string element;
      unsigned count;
    };
    TableElem hashTable[TABLE_SIZE];
    string filename;
    int hashkey(const string);

  public:
    HashPython();
    bool findWord(const string);
    void printHashTable() const;
    void clearCounts();
};
#endif