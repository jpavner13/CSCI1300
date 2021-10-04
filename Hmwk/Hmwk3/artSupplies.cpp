// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 3 - Problem #3

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int numOfStudents;
    double totalCost;
    cout << "Enter the number of students in the school district:" << endl;
    cin >> numOfStudents;
    if(numOfStudents < 0){
        cout << "Invalid input." << endl;
    } else if (numOfStudents <= 99){
        totalCost = 5.50 * numOfStudents;
        cout << "The total cost for buying art kits is $" << std::fixed << std::setprecision(2) << totalCost << endl;
    } else if (numOfStudents <= 199){
        totalCost = (5.50 * .9) * numOfStudents;
        cout << "The total cost for buying art kits is $" << std::fixed << std::setprecision(2) << totalCost << endl;
    } else if (numOfStudents <= 399){
        totalCost = (5.50 * .85) * numOfStudents;
        cout << "The total cost for buying art kits is $" << std::fixed << std::setprecision(2) << totalCost << endl;
    } else if (numOfStudents <= 599){
        totalCost = (5.50 * .8) * numOfStudents;
        cout << "The total cost for buying art kits is $" << std::fixed << std::setprecision(2) << totalCost << endl;
    } else {
        totalCost = (5.50 * .75) * numOfStudents;
        cout << "The total cost for buying art kits is $" << std::fixed << std::setprecision(2) << totalCost << endl;
    }
    return 0;
}