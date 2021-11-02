#include "Song.h"
#include <iostream>
using namespace std;

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