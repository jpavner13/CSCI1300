// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 3 - Problem #4

#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Enter boxers' weights" << endl;
    cin >> a >> b >> c;

    if((a < b) && (b < c)){
        cout << "Ascending order" << endl;
    } else if((a > b) && (b > c)) {
        cout << "Descending order" << endl;
    } else {
        cout << "Neither";
    }
    return 0;
}