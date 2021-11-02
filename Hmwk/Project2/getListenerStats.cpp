#include <iostream>
#include "Listener.h"
#include "Song.h"
using namespace std;

int getListenerStats(string name, Listener listeners[], int numListenersStored, int numSongs){
    bool inList = false;
    for(int i = 0; i < numListenersStored; i++){
        if(listeners[i].getListenerName() == name){
            inList = true;
            int uniqueSongs = listeners[i].getNumUniqueSongs();
            int totalPlays = 0;
            for(int x = 0; x < numSongs; x++){
                totalPlays += listeners[i].getPlayCountAt(x);
            }
            string listenerName = listeners[i].getListenerName();
            double average = double(totalPlays) / double(uniqueSongs);
            if(average > 0){
                cout << listenerName << " listened to " << uniqueSongs << " songs." << endl;
                cout << listenerName << "'s average number of listens was " << fixed << setprecision(2) << average << endl;
                return 1;
            } else {
                cout << listenerName << " has not listened to any songs." << endl;
                return 0;
            }
        }
    }
    if(!inList){
        cout << name << " does not exist." << endl;
        return -3;
    }
}