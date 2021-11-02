#include "Song.h"
#include <iostream>
using namespace std;

Song:: Song(){
    title = "";
    artist = "";
    genre = "";
}

Song::Song(string t, string a, string g){
    title = t;
    artist = a;
    genre = g;
}

string Song::getArtist(){
    return artist;
}
void Song::setArtist(string s){
    artist = s;
}

string Song::getTitle(){
    return title;
}
void Song::setTitle(string s){
    title = s;
}

string Song::getGenre(){
    return genre;
}
void Song::setGenre(string s){
    genre = s;
}

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

int Song::readSongs(string fileName, Song arr[], int numSongsStored, int arrSize){
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

void Song::printAllSongs(Song arr[], int numStored){
    if(numStored <= 0){
        cout << "No songs are stored" << endl;
    } else {
        cout << "Here is a list of songs" << endl;
        for(int i = 0; i < numStored; i++){
            string artist = arr[i].getArtist();
            string title = arr[i].getTitle();
            cout << title << " is by " << artist << endl;
        }
    }
}

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

int Song::countGenre(string genre, Song arr[], int numStored){
    int count = 0;
    for(int i = 0; i < numStored; i++){
        string str = lowerCase(arr[i].getGenre());
        if(str == lowerCase(genre)){
            count++;
        }
    }
    return count;
}

int Song::frequentGenreSongs(Song arr[], int numSongStored){
    Song songs[50];
    for(int i = 0; i < numSongStored; i++){
        songs[i] = arr[i];
    }
    int max;
    for(int i = 0; i < numSongStored; i++){
        int currentMax = 0;
        string currentGenre = songs[i].getGenre();
        cout << "Current genre is: " << currentGenre << endl;
        for(int x = 0; x < numSongStored; x++){
            cout << songs[x].getGenre();
            if(songs[x].getGenre() == currentGenre){
                currentMax++;
            }
        }
        cout << currentMax << endl;
        if(currentMax < max){
            max = currentMax;
        }
    }
    return max;
}