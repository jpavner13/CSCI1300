// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 4 - Problem #2

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int input;
    cout << "Enter a positive integer:" << endl;
    cin >> input;

    long int current = input;

    if(input <= 0){
        cout << "Invalid input." << endl;
    } else {
        cout << current << endl;
        while(current > 1){
            if ((current % 2) == 1){
                current = floor(pow((sqrt(current)), 3));
            } else {
                current = floor(sqrt(current));
            }
            cout << current << endl;
        }
    }
    return 0;
}