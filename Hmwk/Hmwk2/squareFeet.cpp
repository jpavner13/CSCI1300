// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 2 - Problem #3

#include <iostream>
# include <iomanip>
using namespace std;

int main(){                                                             //Initialize main function
    double length, width;                                               //Initialize variables for length and width
    cout << "Enter the length of side a in inches:" << endl;            //Print "Enter side 1"
    cin >> length;                                                      //set input to length
    cout << "Enter the length of side b in inches:" << endl;            //print "enter side 2"
    cin >> width;                                                       //Set to width

    double areaInFeet = (length / 12) * (width / 12);                   //Do math for area
    cout << "The area of the rectangular field is " << setprecision(2) << fixed << areaInFeet << " square feet" << endl; //Print output
    return 0;                                                           //Return data type
}