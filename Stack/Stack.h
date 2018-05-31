#ifndef Stack_h
#define Stack_h
#include <string>

using namespace std;

class StackClass {
private:

  struct item {
    string name;
    int value;
    item* prev;
  };

  item* stackPtr;

public:
  void Push(string name, int value);
  void Pop();
  void ReadItem(item* r);
  void Print();

  StackClass(); //constructor
  ~StackClass(); //destructor

};

#endif
