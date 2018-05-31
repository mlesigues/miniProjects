#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

int main(int argc, char** argv) {

  StackClass myStack;

  myStack.Push("Eggs", 49);
  myStack.Push("Bacon", 13);
  myStack.Push("Grits", 8);
  myStack.Push("Sausage", 2);
  myStack.Print();
  cout << "Pop function is called\n";
  myStack.Pop();
  cout << "Pop function is called\n";
  myStack.Pop();
  cout << "Pop function is called\n";
  myStack.Pop();
  cout << "Pop function is called\n";
  myStack.Pop();
  cout << "Pop function is called\n";
  myStack.Pop();
  cout << "\n\nNew stack\n\n";
  myStack.Push("Bread", 69);
  myStack.Push("Orange juice", 9);
  myStack.Print();

}
