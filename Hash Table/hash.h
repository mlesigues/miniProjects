#ifndef hash_h
#define hash_h
#include <string>

using namespace std;

struct data {
  int key;
  string value;
};

class hTable {
private:
  data *item;
  int maxSize;
  int numEl;

public:
  hTable(); //constructor
  hTable(int tablesize); //constructor that takes table size
  int hash(int &k); //evaluates hash code of key
  int rehash(int &k); //linear probing
  int add(data &d);
  int remove(data &d);
  void print();
};


#endif
