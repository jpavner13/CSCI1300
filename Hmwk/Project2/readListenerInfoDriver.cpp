#include "Listener.h"
#include <iostream>
#include <fstream>
using namespace std;

int split(string str, char sep, string arr[], int arrSize){
    string current = "";
    int count = 1;
    if(str.length() < 1){
        count = 0;
    }
    int arrCurrent = 0;
    int length = str.length();
    for(int i = 0; i < length; i++){
        if(str[i] == sep){
            arr[arrCurrent] = current;
            current = "";
            arrCurrent++;
            count++;
        } else {
            current += str[i];
        }
    }
    if(arrSize < count){
        count = -1;
    }
    arr[arrCurrent] = current;
    return count;
}

int readListenerInfo(string fileName, Listener listeners[], int numListenersStored, int listenerArrSize, int maxCol){
    if(numListenersStored >= listenerArrSize){
        return -2;
    }
    ifstream file;
    file.open(fileName);
    bool isEmpty = true;
    if(file.is_open()){
        string str;
        while(getline(file, str)){
            if(numListenersStored < listenerArrSize){
                if(str.length() != 0){
                    isEmpty = false;
                    string vals[maxCol];
                    int numCols = split(str, ',', vals, maxCol);
                    string name = vals[0];
                    int listens[numCols - 1];
                    for(int i = 0; i < (numCols - 1); i++){
                        listens[i] = stoi(vals[i + 1]);
                    }
                    Listener listener = Listener(name, listens, (numCols - 1));
                    listeners[numListenersStored] = listener;
                    numListenersStored++;
                }
            }
        }
    } else {
        return -1;
    }
    if(isEmpty){
        return 0;
    }
    return numListenersStored;
}

int main(){
    Listener listeners[100];
    cout << readListenerInfo("listeners.txt", listeners, 0, 100, 50) << endl;
}