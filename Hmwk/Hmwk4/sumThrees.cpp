// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 4 - Problem #1

#include <iostream>

using namespace std;

int main(){
    int input;
    cout << "Enter a positive integer:" << endl;
    cin >> input;

    int sum = 0;
    int i = 0;

    if(input < 0){
        cout << "Invalid input." << endl;
    } else {
        while(i <= input){
            sum += i;
            i += 3;
        }
        cout << "Sum: " << sum << endl;
    }
    return 0;
}