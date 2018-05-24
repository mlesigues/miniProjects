//
//  reverse.cpp
//
//
//  Created by Marielle Lesigues on 5/24/18.
//  Copyright © 2018 mlesigues. All rights reserved.
//

#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int num, reverse = 0, remainder;
    
    cout << "Enter a number: ";
    cin >> num;
    
    while (num != 0) {
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num = num/10;
    }
    cout << "Reverse is: " << reverse << endl;
}
