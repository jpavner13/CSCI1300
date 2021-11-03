// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #9

/*  
    PSUDO CODE:
        1. Check to make sude name passed is valad
        2. Check to see if name is already in the data base
        3. If both casses pass create new listener
        4. Set name of new listener to new name
        5. If there is room in the array, add new listener to the next index in the array
        6. return values
*/

#include <iostream>
#include "Listener.h"
#include "Song.h"
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

int addListener(string name, Listener listeners[], int numSongs, int numListenersStored, int listenerArrSize){
    if(name.length() == 0){
        return -3;
    }
    for(int i = 0; i < numListenersStored; i++){
        if(lowerCase(listeners[i].getListenerName()) == lowerCase(name)){
            return -2;
        }
    }
    Listener newListener;
    newListener.setListenerName(name);
    if(listenerArrSize > numListenersStored){
        listeners[numListenersStored] = newListener;
        numListenersStored++;
    } else {
        return -1;
    }
    return numListenersStored;
}