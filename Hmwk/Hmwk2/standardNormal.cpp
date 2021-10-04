// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 2 - EC Problem

#include <iostream>
#include <cmath>                                                //Include math
using namespace std;

int main(){                                                     //Initialize main function
    double input;                                               //Initialize input
    cout << "Enter a value for x:" << endl;                     //Ask for "x"
    cin >> input;                                               //Set input to x

    double standardNormal;                                      //Initialize var for standardNormal
    standardNormal = ((1.0/(sqrt(2.0 * M_PI))) * (exp((-1.0/2.0) * pow(input, 2.0))));          //Do math(no idea what the math means)
    cout << "The probability at x=" << input << " is " << standardNormal << endl;               //Print output
    return 0;                                                   //Return data type
}