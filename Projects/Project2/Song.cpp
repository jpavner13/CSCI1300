// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #1

/*  
    PSUDO CODE:
        . Include Song.h
        2. Create all function inner workings as defined in the Song.h file
        3. Return all expected values from each function
*/

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