// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 7 - Problem #1

#include <iostream>
#include <string>
using namespace std;

class State{
    public:
    State();
    State(string name, int population, int mileage);

    void setName(string newName);
    void setPopulation(int newPop);
    void setSquareMileage(int newMilege);

    string getName();
    int getPopulation();
    int getSquareMileage();

    double getPopulationDensity();

    private:
    string name;
    int population;
    int mileage;
};