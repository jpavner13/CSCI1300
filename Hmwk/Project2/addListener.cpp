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
    int totalInArr = numListenersStored;
    for(int i = 0; i < numListenersStored; i++){
        if(lowerCase(listeners[i].getListenerName()) == lowerCase(name)){
            return -2;
        }
    }
    Listener newListener;
    newListener.setListenerName(name);
    if(listenerArrSize > numListenersStored){
        listeners[numListenersStored] = newListener;
        totalInArr++;
    } else {
        return -1;
    }
    return totalInArr;
}