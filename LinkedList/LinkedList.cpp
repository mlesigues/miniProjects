#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

using namespace std;


List::List() {
  head = NULL;
  curr = NULL;
  temp = NULL;
}

void List::AddNode(int addData) { //adding at the end
  nodePtr n = new node;
  n->next =  NULL;
  n->data = addData;

  if(head != NULL) {
    curr = head;
    while(curr->next != NULL) { //advances the current ptr until it gets to the last node of the list
      curr = curr->next;
    }
    curr->next = n;
  }
  else { //if we don't have a list, do this
    head = n;
  }
}

void List::DeleteNode(int delData) {
  nodePtr delPtr = NULL;
  temp = head;
  curr = head;
  while (curr != NULL && curr->data != delData) { //traverses the list
    //advance temp and curr ptrs
    temp = curr;
    curr = curr->next;
  }
  if(curr == NULL) {
    cout << delData << " was not in the list.\n";
    delete delPtr;
  }
  else {
    delPtr = curr;
    curr = curr->next;
    temp->next = curr;
    if(delPtr == head) {
      head = head->next;
      temp = NULL;
    }
    delete delPtr;
    cout << "The value " << delData << " was deleted.\n";
  }
}

void List::PrintList() {
  curr = head;
  while(curr != NULL) {
    cout << curr->data << endl;
    curr = curr->next;
  }
}
