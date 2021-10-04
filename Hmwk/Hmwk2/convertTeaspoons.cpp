// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 2 - Problem #5

#include <iostream>
using namespace std;

int main(){                                                         //Initialize main function
    int teaspoons;                                                  // Initialize teaspoons
    cout << "Enter the number of teaspoons:" << endl;               //Print "Enter teaspoons"
    cin >> teaspoons;                                               // set input to teaspoons

    int cups, tablespoons;                                          //Initialize cups and tablespoons
    cups = teaspoons / 48;                                          //Get cups
    tablespoons = (teaspoons % 48) / 3;                             //Get tablespoons
    teaspoons -= ((cups * 48) + (tablespoons * 3));                 //Get remainder
    cout << cups << " cup(s) " << tablespoons << " tablespoon(s) " << teaspoons << " teaspoon(s)" << endl; //Print output
    return 0;                                                       //Return data type
}