// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #1

/*  
    PSUDO CODE:
        1. Initialize class
        2. Create public and private sections to the class
        3. Define all public functions(do not add any inner workings to the functions at this time)
        4. Define all private variables that can only be accessed through the functions
*/

#include <iostream>
#include <string>
#include <fstream>
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

    int countGenre(string genre, Song arr[], int numStored);
    int readSongs(string fileName, Song arr[], int numSongsStored, int arrSize);
    void printAllSongs(Song arr[], int numStored);
    int frequentGenreSongs(Song arr[], int numSongStored);

    private:
    string title;
    string artist;
    string genre;
};