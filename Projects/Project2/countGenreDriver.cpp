// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #4

/*  
    PSUDO CODE:
        1. Define a counter to count number of the genre
        2. Test each song to see if the genre matches the given genre
        3. Increment counter if the genre matches
        4. Return the counter value
*/

#include "Song.h"
#include "Song.cpp"
#include <iostream>
using namespace std;

string lowerCase(string str){
    string returnString = "";
    for(int i = 0; i < str.length(); i++){
        char c = str[i];
        int val = c;
        if(val > 64 && val < 91){
            char newChar = val + 32;
            returnString += newChar;
        } else {
            returnString += c;
        }
    }
    return returnString;
}

int countGenre(string genre, Song arr[], int numStored){
    int count = 0;
    for(int i = 0; i < numStored; i++){
        string str = lowerCase(arr[i].getGenre());
        if(str == lowerCase(genre)){
            count++;
        }
    }
    return count;
}