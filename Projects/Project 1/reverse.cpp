// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 1 - Problem #1

/*
    intialize new string to push reverse into
    go through each char in the string starting at the last char and moving up
    push current char into the new string
    return reversed string
*/

#include <iostream>
using namespace std;

void reverse(string s){
    int length = (s.length() - 1);
    string inverted;
    for(int i = length ; i >= 0; i--){
        char letter = s[i];
        inverted += letter; 
    }
    cout << inverted << endl;
}

int main(){
    reverse("1234567890");
    reverse("0987654321");
    reverse("5678901234");
    return 0;
}