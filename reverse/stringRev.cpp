#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string str1;
	cout << "Enter a string: ";
	getline(cin, str1);

	cout << "The reverse is: ";
	reverse(str1.begin(), str1.end());
	cout << str1 << endl;

	return 0;
}
