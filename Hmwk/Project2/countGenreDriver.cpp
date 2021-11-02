#include "Song.h"
#include "Song.cpp"
#include <iostream>
using namespace std;

int main(){
    Song arr[50];
    int x = readSongs("songs.txt", arr, 0, 50);
    Song song = arr[0];
    cout << song.countGenre("Rock", arr, 50) << endl;
}