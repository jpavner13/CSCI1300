// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 1 - Problem #2

/*
    create bool to return
    test to see if the char is a vowel (undercase or caps)
    if it's a vowel, set bool to false
    else set bool to true
    return bool
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