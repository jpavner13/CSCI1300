// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #5

/*  
    PSUDO CODE:
        1. Create an array of songs to be edited without affecting the main array(reduces repition and run time)
        2. Define a counter for the highest num of genre occurrences
        3. Define a temporary counter for num of genres in array
        4. Cycle through each song in the array and test it's genre againced the rest
        5. If the genre matches, increment temporary counter and remove the song from the temporary array(prevents from being retested)
        6. Test to see if temporary genre count is greater than the max count thus far
        7. If it is, set max counter to the current count of genre
        8. return max value
*/

#include <iostream>
#include "Song.h"
using namespace std;

int frequentGenreSongs(Song arr[], int numSongStored){
    Song songs[50];
    for(int i = 0; i < numSongStored; i++){
        songs[i] = arr[i];
    }
    int max;
    for(int i = 0; i < numSongStored; i++){
        int currentMax = 0;
        string currentGenre = songs[i].getGenre();
        for(int x = 0; x < numSongStored; x++){
            if(songs[x].getGenre() == currentGenre){
                currentMax++;
            }
        }
        if(currentMax > max){
            max = currentMax;
        }
    }
    return max;
}