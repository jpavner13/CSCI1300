// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 6 - Problem #2

#include <iostream>
#include "State.h"
using namespace std;

int minPopulation(State states[], int size){
    if(size <= 0){
        return -1;
    } else {
        int counter = 0;
        int minPopulationIndex = 0;
        for(int i = 0; i < size; i++){
            if(states[i].getPopulation() < states[minPopulationIndex].getPopulation()){
                minPopulationIndex = i;
            }
        }
        return minPopulationIndex;
    }
}

int main(){
    State states[5];
    states[0] = State("Colorado", 5893634, 104094);
    states[1] = State("California", 39613493,163695);
    states[2] = State("Nebraska", 1951996, 77348);

    int index = minPopulation(states, 3);
    cout << states[index].getName() << endl;
    cout << states[index].getPopulation() << endl;
    cout << states[index].getSquareMileage() << endl;
    return 0;
}