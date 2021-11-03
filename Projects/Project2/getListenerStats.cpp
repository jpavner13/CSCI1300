// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #10

/*  
    PSUDO CODE:
        1. Define bool valie to represent if the given name is in the array of listeners
        2. Cycle throught the array and test to see if the name matches any of the Listeners
        3. If a match is found, set bool value to true
        4. Run fuctions to get all stats of listener, and set values to specified types
        5. Calculate average(making sure to convert all values to double)
        6. Test if average is greater than 0
        7. If it is, output stats in correct format
        8. If its not return that the listener hasnt listened to any songs
        9. Test to see if the bool(name is in the array) is false
        10. If it is, return -3
*/

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
    return 0;
}