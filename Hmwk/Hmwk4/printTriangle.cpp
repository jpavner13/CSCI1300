// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 4 - Problem #5

#include <iostream>
using namespace std;

int main(){
    int height;
    cout << "Enter the height:" << endl;
    cin >> height;

    int asciiValue = 97;

    for(int i = height; i > 0 ; i--){
        for(int x = 0; x < height; x++){
            if(asciiValue >= 123){
                asciiValue = 97;
            }
            cout << (char)(asciiValue + x) ;
        }
        asciiValue = (asciiValue + height);
        height--;
        cout << endl;
    }
    return 0;
}