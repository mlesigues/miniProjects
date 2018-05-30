#include <iostream>
#include <algorithm>

using namespace std;

/*
Write a program that prints the numbers from 1 to 100 and for multiples of '3' print "Fizz"
instead of the number and for the multiples of '5' print "Buzz".
*/

int main() {
  for (int i = 1; i <= 100; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      cout << "Fizzbuzz\t" << endl;
    }
    else if (i % 3 == 0) {
      cout << "Fizz\t" << endl;
    }
    else if (i % 5 == 0) {
      cout << "Buzz\t" << endl;
    }
    else {
      cout << i << endl;
    }
  }
  return 0;
}
