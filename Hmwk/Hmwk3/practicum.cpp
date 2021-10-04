// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 3 - EC Problem

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double score1, score2, score3;
    double average;
    cout << "Enter practicum 1 score:" << endl;
    cin >> score1;
    cout << "Enter practicum 2 score:" << endl;
    cin >> score2;
    cout << "Enter practicum 3 score:" << endl;
    cin >> score3;
    average = (score1 + score2 + score3) / 3;

    if(average >= 67.00){
        cout << "Practicum average: " << fixed << setprecision(2) << average << endl;
        cout << "You have a passing practicum average." << endl;
    } else {
        cout << "Practicum average: " << fixed << setprecision(2) << average << endl;
        cout << "You can retake practicums during the final." << endl;
    }
    return 0;
}