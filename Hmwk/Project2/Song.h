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

    int readSongs(string fileName, Song arr[], int numSongsStored, int arrSize);
    void printAllSongs(Song arr[], int numStored);
    int countGenre(string genre, Song arr[], int numStored);
    int frequentGenreSongs(Song arr[], int numSongStored);

    private:
    string title;
    string artist;
    string genre;
};