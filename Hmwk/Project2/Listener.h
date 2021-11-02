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
    int getSize();

    int totalPlayCount();
    int getNumUniqueSongs();
    
    private:
    string name;
    static const int size = 50;
    int playCount[size];
};