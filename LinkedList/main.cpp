#include <cstdlib>
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv) {

  List myList;

  myList.AddNode(3);
  myList.AddNode(5);
  myList.AddNode(7);
  myList.PrintList();

  myList.DeleteNode(3);
  myList.PrintList();

  return 0;
}
