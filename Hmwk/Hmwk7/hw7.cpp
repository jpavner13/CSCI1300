// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 7 - Problem #6

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

void printAllSongs(Song arr[], int numStored){
    if(numStored <= 0){
        cout << "No songs are stored" << endl;
    } else {
        cout << "Here is a list of songs" << endl;
        for(int i = 0; i < numStored; i++){
            if(arr[i].getTitle().length() > 0){
                string artist = arr[i].getArtist();
                string title = arr[i].getTitle();
                cout << title << " is by " << artist << endl;
            }
        }
    }
}

int main(){
    Song songs[50];
    bool inLoop = true;
    while(inLoop){
        int choice;
        cout << "======Main Menu=====" << endl;
        cout << "1. Read songs" << endl;
        cout << "2. Print all songs" << endl;
        cout << "3. Quit" << endl;
        cin >> choice;
        if(choice == 1){
            string name;
            cout << "Enter a song filename:" << endl;
            cin >> name;
            int total = readSongs(name, songs, 0, 50);
            if(total == -1){
                cout << "No songs saved to the database." << endl;
            } else if (total == -2){
                cout << "Total songs in the database: 50" << endl;
            } else {
                cout << "Total songs in the database: " << total << endl;
            }
        } else if (choice == 2){
            //int total = readSongs(name, songs, 0, 50);
            printAllSongs(songs, 50);
        } else if(choice == 3){
            cout << "Good bye!" << endl;
            inLoop = false;
        } else {
            cout << "Invalid input." << endl;
        }
    }
    Song songs[50];
    readSongs("songs.txt", songs, 0, 50);

}