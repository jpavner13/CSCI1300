// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 1 - Problem #3

/*
    create a int ocunter
    go through each char in the given string
    use isConstant to test to see if current char is a consonant
    if it is, increase counter by one
    move onto next char
    return counter
*/

#include <iostream>
using namespace std;

bool isConsonant(char c){
    bool isIt;

    if((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U')){
        isIt = false;
    } else {
        isIt = true;
    }

    return isIt;
}

int numConsonant(string s){
    int count;
    for(int length = s.length() - 1; length >= 0; length--){
        if(isConsonant(s[length])){
            count++;
        }
    }
    return count;
}

int main(){

    return 0;
}