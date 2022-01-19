#ifndef CovidList_h
#define CovidList_h
#include <string>
using std::string;

class CovidList
{
  private:
    struct listNode
    {
      string name;
      int section;
      int students;
      int covidnow;
      int covidrecov;
      struct listNode *next;
    };
    listNode *head;

  public:
    CovidList();
    void addClass(string n, int c, int s);
    void addCovid(string n, int a);
    void recovCovid(string n, int c);
    void printInfo() const;
};
#endif
