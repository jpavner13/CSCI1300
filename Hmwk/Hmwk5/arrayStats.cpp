// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 5 - Problem #2

#include <iostream>
#include <float.h>
#include <iomanip>
using namespace std;

void stats(double ints[], int length){
    double product = 1;
    //double min = DBL_MAX;
    double min = ints[0];
    double total;
    for(int i = 0; i < length; i++){
        double current = ints[i];
        product = product * current;
        if(current < min){
            min = current;
        }
        total += current;
    }
    double avg = total / length;
    cout << "Min: " << fixed << setprecision(3) << min << endl;
    cout << "Product: " << fixed << setprecision(3) << product << endl;
    cout << "Avg: " << fixed << setprecision(3) << avg << endl;
}

int main(){
    double arr[] = {1.24, 5.68, 3.456};
    stats(arr, 3);
    return 0;
}