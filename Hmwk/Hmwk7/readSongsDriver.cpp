// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 7 - Problem #4

#include "Song.h"
#include <iostream>
#include <fstream>
using namespace std;

int split(string str, char sep, string arr[], int arrSize){
    string current = "";
    int count = 1;
    if(str.length() < 1){
        count = 0;
    }
    int arrCurrent = 0;
    int length = str.length();
    for(int i = 0; i < length; i++){
        if(str[i] == sep){
            arr[arrCurrent] = current;
            current = "";
            arrCurrent++;
            count++;
        } else {
            current += str[i];
        }
    }
    if(arrSize < count){
        count = -1;
    }
    arr[arrCurrent] = current;
    return count;
}

int readSongs(string fileName, Song arr[], int numSongsStored, int arrSize){
    ifstream file;
    file.open(fileName);
    string str;

    int indexCounter = numSongsStored;

    if(numSongsStored >= arrSize){
        return -2;
    }

    if(file.is_open()){
        while(getline(file, str)){
            if(str.length() != 0){
                Song currentSong;
                string currentLine[3];
                split(str, ',', currentLine, 3);
                currentSong.setArtist(currentLine[1]);
                currentSong.setTitle(currentLine[0]);
                currentSong.setGenre(currentLine[2]);
                arr[indexCounter] = currentSong;
                indexCounter++;
            }
            if(indexCounter == arrSize){
                return indexCounter;
            }
        }
        return indexCounter;
    } else {
        return -1;
    }
}

int main(){
    Song song = Song("Treasure", "Bruno Mars", "Pop");
    Song song2 = Song();

    cout << song.getTitle() << endl;
    cout << song.getArtist() << endl;
    cout << song.getGenre() << endl;
    song.setTitle("Finesse");
    song.setGenre("R&B");
    cout << song.getTitle() << endl;
    cout << song.getArtist() << endl;
    cout << song.getGenre() << endl;

    cout << song2.getArtist() << endl;
    cout << song2.getTitle() << endl;
    cout << song2.getGenre() << endl;
    return 0;
}