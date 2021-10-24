// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 7 - Problem #1/2

#include "State.h"
#include <iostream>
using namespace std;

State::State(){
    name = "";
    population = 0;
    mileage = 0;
}

State::State(string newName, int newPopulation, int newMileage){
    name = newName;
    population = newPopulation;
    mileage = newMileage;
}

void State::setName(string n){
    name = n;
}
void State::setPopulation(int p){
    population = p;
}
void State::setSquareMileage(int m){
    mileage = m;
}

string State::getName(){
    return name;
}
int State::getPopulation(){
    return population;
}
int State::getSquareMileage(){
    return mileage;
}

double State::getPopulationDensity(){
    if(getSquareMileage() == 0){
        return 0;
    } else {
        return(double(getPopulation()) / double(getSquareMileage()));
    }
}