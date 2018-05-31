#include <cstdlib>
#include <iostream>
#include "Stack.h"

using namespace std;


StackClass::StackClass() { //make sure stackPtr is not pointing to anything
  stackPtr = NULL;
}

StackClass::~StackClass() {
  item* p1;
  item* p2;

  p1 = stackPtr;
  while(p1 != NULL) {//means we are pointing to top of the stack
    p2 = p1;
    p1 = p1->prev; //points below
    p2->prev = NULL; //separates the item that p2 is pointing to from stack
    delete p2;
  }
}

void StackClass::Push(string name, int value) {
  item* n = new item;

  n->name = name;
  n->value = value;

  if(stackPtr == NULL) { //this is the 1st item of the stdack
    stackPtr = n;
    stackPtr->prev = NULL;
  }
  else { //if there is already a stack
    n->prev = stackPtr;
    stackPtr = n;
  }
}

void StackClass::ReadItem(item* r) {
  cout << "---------------------\n";
  cout << "name:\t" << r->name << endl;
  cout << "value:\t" << r->value << endl;
  cout << "---------------------\n";
}

void StackClass::Pop() {

  if(stackPtr == NULL) { //empty stack or base case
    cout << "There is nothing on the stack" << endl;
  }
  else {
    item* p = stackPtr;
    ReadItem(p);
    stackPtr = stackPtr->prev; //points to 2nd to the top item
    p->prev = NULL; //separates top item to the stack
    delete p;
  }
}

void StackClass::Print() {//print contents in the stack
  item* p = stackPtr;

  while(p != NULL) {//if there are items on the stack
    ReadItem(p);
    p = p->prev;
  }

}
