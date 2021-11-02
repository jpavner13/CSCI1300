#include <iostream>
#include "Song.h"
#include "Listener.h"
using namespace std;

void smartPlaylist(string name, string genre, Listener listeners[], Song songs[], int numListeners, int numSongs){
    int highDotProductIndex = -1;
    bool nameExists = false;
    int nameIndex = -1;
    for(int i = 0; i < numListeners; i++){
        if(lowerCase(listeners[i].getListenerName()) == lowerCase(name)){
            nameExists = true;
            nameIndex = i;
        }
    }

    if(!nameExists){
        cout << name << " does not exist." << endl;
    } else {
        int highScore = 0;
        for(int i = 0; i < numListeners; i++){
            if(i != nameIndex){
                int currentScore = 0;
                for(int x = 0; x < numSongs; x++){
                    currentScore += (listeners[nameIndex].getPlayCountAt(x) * listeners[i].getPlayCountAt(x));
                }
                if(currentScore >= highScore){
                    highScore = currentScore;
                    highDotProductIndex = i;
                }
            }
        }
        Song reccomendations[5];
        int counter = 0;
        for(int i = 0; i < numSongs; i++){
            if(songs[i].getGenre() == genre){
                if(listeners[nameIndex].getPlayCountAt(i) == 0){
                    if(counter < 5){
                        reccomendations[counter] = songs[i];
                        counter++;
                    }
                }
            }
        }
        if(counter == 0){
            cout << "There are no recommendations for " << name << " at present." << endl;
        } else {
            cout << "Here is the playlist:" << endl;
            for(int i = 0; i < counter; i++){
                cout << "Title: " << reccomendations[i].getTitle() << ", Artist: " << reccomendations[i].getArtist() << endl;
            }
        }
    }
}