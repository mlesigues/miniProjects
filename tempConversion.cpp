#include <iostream>

using namespace std;

int main() {
int userInput;
float celsius, fahrenheit;

cout << "--------------------------------------------------------------------" << endl;
cout << "This program converts celsius to fahrenheit or vice versa." << endl;
cout << "--------------------------------------------------------------------" << endl;
cout << "Choose which conversion: " << endl;
cout << "Celsius to Fahrenheit is 1." << endl;
cout << "Fahrenheit to Celsius is 2." << endl;
cout << "Input:\t";
cin >> userInput;

  if(userInput == 1) {
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    fahrenheit = (celsius  * 1.8) + 32;
    cout << "The Fahrenheit equivalent is: " << fahrenheit << endl;
  }
  else if(userInput == 2) {
    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;
    celsius = (fahrenheit - 32)/1.8;
    cout << "The Celsius equivalent is: " << celsius << endl;
  }
  else {
    cout << "Wrong choice!" << endl;
  }

  return 0;
}
