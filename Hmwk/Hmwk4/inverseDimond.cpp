// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 4 - Problem #6

#include <iostream>
using namespace std;

void printLength(int length){
    string stars;
    for(int i = 0; i < length; i++){
        stars = stars + "*";
    }
    cout << stars;
}
void printSpaces(int length){
    string spaces;
    for(int i = 0; i < (length * 2); i++){
        spaces = spaces + " ";
    }
    cout << spaces;
}

int main(){
    int length;
    cout << "Enter the length:" << endl;
    cin >> length;

    for(int i = (length - 1); i >= 1; i-- ){
        printLength(i);
        printSpaces(length - i);
        printLength(i);
        cout << endl;
    }
    for(int i = 1; i <= (length - 1); i++ ){
        printLength(i);
        printSpaces(length - i);
        printLength(i);
        cout << endl;
    }

    return 0;
}