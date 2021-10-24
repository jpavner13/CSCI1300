// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 7 - Problem #3

#include <iostream>
#include <string>
using namespace std;

class Song{
    public:
    Song();
    Song(string title, string artist, string genre);

    string getTitle();
    void setTitle(string newTitle);
    string getArtist();
    void setArtist(string newArtist);
    string getGenre();
    void setGenre(string newGenre);

    int readSongs(string fileName, Song arr[], int numSongsStored, int arrSize);

    private:
    string title;
    string artist;
    string genre;
};