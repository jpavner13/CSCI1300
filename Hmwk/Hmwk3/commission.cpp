// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 3 - Problem #2

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double revinue;
    double commission;
    cout << "Enter the value for revenue:" << endl;
    cin >> revinue;
    if(revinue <= 65000){
        commission = revinue * .1 ;
    } else {
        commission = (65000 * .1) + ((revinue - 65000) * .25);
    }

    if(commission >= 0){
        cout << "The commission that you earn is $" << std::fixed << std::setprecision(2) << commission << endl;
    } else {
        cout << "Invalid input." << endl;
    }
    return 0;
}