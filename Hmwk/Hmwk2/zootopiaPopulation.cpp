// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 2 - Problem #4

#include <iostream>
#include <algorithm>
using namespace std;

int main(){                                                         //Initialize main function
    int years;                                                      //Initialize years
    cout << "Enter the number of years to estimate:" << endl;       //Print "Enter years"
    cin >> years;                                                   //Set input to years
    int foxes   = 18000;                                            //Set foxes
    int bunnies = 21000;                                            //Set bunnies
    int sloths  = 10000;                                            //Set sloths
    for (int i = 0; i < years; i++){                                //repeat years amout of times
        foxes += (115 - 100);                                       //new fox population
        bunnies += (90 -80);                                        //new bunnies population
        sloths += (70 - 120);                                       //new sloths population
    }
    cout << "There will be " << max(foxes, 0) << " foxes, " << max(bunnies, 0) << " bunnies, and " <<
        max(sloths, 0) << " sloths in " << years << " years." << endl; //Print output
    return 0;                                                       //Return data type
}