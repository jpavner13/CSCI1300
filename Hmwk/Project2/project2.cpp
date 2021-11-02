#include <iostream>
#include "Song.h"
#include "Listener.h"
#include <fstream>
using namespace std;

void printOptions(){
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read songs from file" << endl;
    cout << "2. Print all songs" << endl;
    cout << "3. Song-count by genre" << endl;
    cout << "4. Songs from most common genre" << endl;
    cout << "5. Add listener" << endl;
    cout << "6. Read listens from file" << endl;
    cout << "7. Get number of listens by a listener" << endl;
    cout << "8. Get listener statistics" << endl;
    cout << "9. Quit" << endl;
}

int main(){
    Song songs[50];
    Listener listeners[100];
    int numSongs = 0;
    int numListeners = 0;
    int input = 0;
    while(input != 9){
        printOptions();
        cin >> input;
        switch(input){
            case 1:
                string fileName;
                cout << "Enter a song file name" << endl;
                cin >> fileName;
                int totalSongs = Song::readSongs(fileName, songs, numSongs, 50);
                if(totalSongs == -1){
                    cout << "No songs saved to the database." << endl;
                } else if (totalSongs == -2){
                    cout << "Database is already full. No songs were added." << endl;
                } else {
                    cout << "Total songs in the database: " << totalSongs << endl;
                    numSongs += totalSongs;
                }
                if(numSongs >= 50){
                    cout << "Database is full. Some songs may have not been added." << endl;
                }
                break;
            case 2:
                Song::printAllSongs(songs, numSongs);
                break;
            case 3:
                string genre;
                cout << "Enter a genre" << endl;
                cin >> genre;
                int totGenre = Song::countGenre(genre, songs, numSongs);
                cout << "Total " << genre << " songs in the database: " << totGenre << endl;
                break;
            case 4:
                int commonGenre = Song::frequentGenreSongs(songs, numSongs);
                cout << "Number of songs in most common Genre: " << commonGenre << endl;
                break;
            case 5:
                string currentName;
                cout << "Enter a listener name:" << endl;
                cin >> currentName;
                int add = Listener::addListener(currentName, listeners, 50, numListeners, 100);
                if(add == -1){
                    cout << "Database is already full. Listener cannot be added." << endl;
                } else if(add == -2){
                    cout << "Listener already exists." << endl;
                } else if(add == -3){
                    cout << "The listenerName is empty." << endl;
                } else {
                    cout << "Welcome, " + currentName << "!" << endl
                    listeners[numListeners] = Listener newListener();
                    listeners[numListeners].setListenerName(currentName);
                    numListeners++;
                }
                break;
            case 6:
                string fileName;
                cout << "Enter the listener info file name:" << endl;
                cin >> fileName;
                int readListener = Listener::readListenerInfo(fileName, listeners[], numListeners, 100, 51);
                if(readListener == -1){
                    cout << "Nothing saved to the database." << endl;
                } else if (readListener == -2){
                    cout << "Database is already full. Nothing was added." << endl;
                } else {
                    cout << "Total listeners in the database: " << readListener << endl;
                    if(readListener >= 100){
                        cout << "Database is full. Some listeners may have not been added." << endl;
                    }
                }
            case 7:
                string name;
                string song;
                cout << "Enter a listener name:" << endl;
                cin >> name;
                cout << "Enter a song name:" << endl;
                cin >> song;
                int songIndex;
                int nameIndex;
                for(int i = 0; i < numListeners; i++){
                    if(listeners[i].getListenerName() == name){
                        nameIndex = i;
                    }
                }
                for(int i = 0; i < numSongs; i++){
                    if(songs[i].getTitle() == song){
                        songIndex = i;
                    }
                }
                int playCount = listeners[nameIndex].getPlayCountAt(songIndex);
                if(playCount == -1){
                    cout << song << " does not exist." << endl;
                } else if(playCount == -2){
                    cout << name << " does not exist." << endl;
                } else if(playCount == -3){
                    cout << name << " and " << song << " do not exist." << endl;
                } else {
                    cout << name << " has listened to " << song << playCount << " times." << endl;
                }
                break;
            case 8:
                string name;
                cout << "Enter a listener name:" << endl;
                cint >> name;
                int stats = getListenerStats(name, listeners, numListeners, numSongs);
                break;
            case 9:
                cout << "Good bye!" << endl;
        }

    }
}