#ifndef LinkedList_h
#define LinkedList_h

class List {
private: //data

  typedef struct node {
    int data;
    node* next; //points to the next node in the list
  }* nodePtr;

//  typedef struct node* nodePtr;

  nodePtr head; //because of typedef, node* to nodePtr
  nodePtr curr;
  nodePtr temp;

public: //functions

  List(); //constructor
  void AddNode(int addData);
  void DeleteNode(int delData);
  void PrintList();

};

#endif
