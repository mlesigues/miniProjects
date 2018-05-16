//
//  main.cpp
//  p-2.1
//
//  Created by Marielle Lesigues on 5/16/18.
//  Copyright © 2018 mlesigues. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int userInput;
    cout << "Enter a positive integer greater than 2: ";
    cin >> userInput;
    
    int remainder;
    
    remainder = userInput % 2;
    
    if(remainder == 0) {
        cout << "Success, it is divisible by 2!" << "\n";
    }
    else {
        cout << "Here is the remainder: " << remainder << "\n";
    }
    
    return 0;
}
