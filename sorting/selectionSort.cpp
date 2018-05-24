#include <iostream>
#define MAX_INT 2147483647

using namespace std;

int main(int argc, char **argv) {
  int *arraylist;
  int length = 1;
  int i, j, temp;

  cout << "Enter length of the array: ";
  cin >> length;
  arraylist = new int[length];
  cout << "Enter elements: ";
  for (i = 0; i < length; i++) {
    cin >> arraylist[i];
  }

  cout <<"Sorted array using selection sort: ";
  for (i = 0; i < length; i++) {
    //swapping is happenning here
    temp = arraylist[i];
    j = i - 1;
    while((temp < arraylist[j]) && (j >= 0)) {
      arraylist[j+1] = arraylist[j];
      j = j - 1;
    }
    arraylist[j+1] = temp;
  }
//  cout << "Sorted array: ";
  for (i = 0; i < length; i++) {
    cout << arraylist[i] << " ";
  }
  cout << endl;

  delete[] arraylist;
  return 0;
}
