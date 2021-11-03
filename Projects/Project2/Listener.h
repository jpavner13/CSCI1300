// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #6

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

class Listener{
    public:
    Listener();
    Listener(string nameSet, int plays[], int sizeArr);

    string getListenerName();
    void setListenerName(string newName);

    int getPlayCountAt(int i);
    bool setPlayCountAt(int index, int newInt);

    int totalPlayCount();

    int getNumUniqueSongs();

    int getSize();
    
    int addListener(string name, Listener listeners[], int numSongs, int numListenersStored, int listenerArrSize);
    int readListenerInfo(string fileName, Listener listeners[], int numListenersStored, int listenerArrSize, int maxCol);
    int getListenerStats(string name, Listener listeners[], int numListenersStored, int numSongs);
    
    private:
    string name;
    static const int size = 50;
    int playCount[size];
};