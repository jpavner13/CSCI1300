// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #8

/*  
    PSUDO CODE:
        1. Test to see if Song and Name both exist
        2. If not, print errors
        3. If so, cycle through songs and find index of song
        5. Cycle through names and find index of name
        6. Return playcount of song by name using getPlayCountAt and the indecies previously found
*/

#include "Song.h"
#include "Listener.h"
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

int getSongPlayCount(string name, string songName, Listener listeners[], Song songs[], int numListeners, int arrSongs){
    bool songFound = false;
    bool nameFound = false;
    int listenerIndex = 0;
    for(int i = 0; i < numListeners; i++){
        //cout << "in loop" << endl;
        //cout << listeners[i].getListenerName() << endl;
        if(lowerCase(listeners[i].getListenerName()) == lowerCase(name)){
            //cout << "Found listener" << endl;
            nameFound = true;
            listenerIndex = i;
        }
        
    }
    for(int x = 0; x < arrSongs; x++){
        if(lowerCase(songs[x].getTitle()) == lowerCase(songName)){
            //cout << "Found song" << endl;
            songFound = true;
            if(nameFound){
                return listeners[listenerIndex].getPlayCountAt(x);
            }
        }
    }
    if(!nameFound && !songFound){
        return -3;
    } else if(!nameFound){
        return -2;
    } else {
        return -1;
    }
}

int main(){
    Song songs[50];
    int numSongsStored = readSongs("songs2.txt", songs, 0, 50);
    int numListenersStored = 0;
    int listenerArrSize = 50;
    Listener listener[listenerArrSize];
    numListenersStored = readListenerInfo("listenerInfo.txt", listener, numListenersStored, listenerArrSize, 50);
    cout<<getSongPlayCount("John", "Goodbye Yellow Brick Road", listener, songs, numListenersStored, numSongsStored)<<endl;
}