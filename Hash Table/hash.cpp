#include "hash.h"
#include <iostream>

using namespace std;

hTable::hTable() {
  maxSize = 23;
  item = new data[maxSize];
  numEl = 0;

  for(int i = 0; i < maxSize; i++) {
    item[i].key = -1;
    item[i].value = "N/A";
  }
}

hTable::hTable(int tablesize) {
  maxSize = tablesize; //size of table = input parameter
  item = new data[maxSize];
  numEl = 0;

  for(int i = 0; i < maxSize; i++) {
    item[i].key = -1;
    item[i].value = "N/A";
  }
}

int hTable::hash(int &k) { //h = key % table size
  return k % maxSize; //the remainder is what we want
}

int hTable::rehash(int &k) {
  return (k+1) % maxSize; //we are doing linear probing
}

int hTable::add(data &d) {
  if(numEl == maxSize) { //checks if the table is full
    return -1;
  }

  int element = hash(d.key); //element is the result of the hash code
  if(item[element].key == -1) { //if the table is empty, add key & value
    item[element].key = d.key;
    item[element].value = d.value;
    numEl++;
    return 0;
  }
  else {
    for(int i = 0; i < item[element].key; i++) { //if there's collision, rehash until a space is available
      if(item[element].key != -1) {
        element = rehash(element);
      }
    }
    //after rehashing, add key & value
    item[element].key = d.key;
    item[element].value = d.value;
    numEl++;
    return 0;
  }
}

int hTable::remove(data &d) {
  if(numEl == 0) { //table is empty, do nothing!
    return -1;
  }

  int element = hash(d.key);
  if(item[element].key == d.key) {//is key same as the hash code key?
    item[element].key = -1;
    item[element].value = "N/A";
    numEl--;
    return 0;
  }
  else {
    int check = element;
    while(item[element].key != d.key && item[element].value != d.value) { //if collusion occurs, do this
      element = rehash(element);
      if(check == element) { //data pair is not found
        return -1;
      }
    }
    item[element].key = -1; //keys founds, goes back to intial value & key
    item[element].value = "N/A";
    numEl--;
    return 0;
  }
}

void hTable::print() {
  for(int i = 0; i < maxSize; i++) {
    cout << i << "--> " << item[i].key << "\t\t" << item[i].value << endl;
  }
  cout << "There are " << numEl << " data in the table." << endl;
}
