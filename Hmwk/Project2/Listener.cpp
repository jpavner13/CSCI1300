#include "Listener.h"
#include <iostream>
#include <string>
using namespace std;

Listener:: Listener(){
    name = "";
    for(int i = 0; i < size; i++){
        playCount[i] = 0;
    }
}
Listener:: Listener(string nameSet, int plays[], int sizeArr){
    name = nameSet;
    for(int i = 0; i < sizeArr; i++){
        playCount[i] = plays[i];
    }
    for(int i = sizeArr; i < 50; i++){
        playCount[i] = 0;
    }
}

string Listener::getListenerName(){
    return name;
}

void Listener::setListenerName(string newName){
    name = newName;
}

int Listener::getPlayCountAt(int i){
    if(i <= size && i >= 0){
        return playCount[i];
    } else {
        return -1;
    }
}
bool Listener:: setPlayCountAt(int index, int newInt){
    if(index <= size && index >= 0 && newInt > 0){
        playCount[index] = newInt;
        return true;
    } else {
        return false;
    }
}

int Listener::getSize(){
    return size;
}

int Listener::totalPlayCount(){
    int total = 0;
    for(int i = 0; i < size; i++){
        total += playCount[i];
    }
    return total;
}

int Listener::getNumUniqueSongs(){
    int num = 0;
    for(int i = 0; i < size; i++){
        if(playCount[i] >= 1){
            num++;
        }
    }
    return num;
}