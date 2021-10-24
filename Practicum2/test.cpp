#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
void printSeriesHalfSixth(int n) {
    int sum = 0;
    int i = 1;
    while (i <= n) {
        if (i % 6 == 0) {
            //If the number is divisible by 6, print its half value and add the half value to the sum
            cout << i/2;
            sum = sum + i/2;
        }
        else {
            //If the number is not divisible by 6, print the number and add the number to the sum
            cout << i ;
            sum = sum + i;
        }
        if(i != n){
            //This check is added to not print the last '+'
            cout<<" + ";
        }
        i++;
    }
    cout << endl << "Result of the series is " << sum << endl;
}

int CountCtoK(string s){
    int count = 0;
    if(s.length() == 0){
        return -1;
    } else {
        for(int i = 0; i < s.length(); i++){
            int test = int(s[i]);
            if((test >= 67 && test <= 75) || (test >= 99 && test <= 107)){
                count++;
            }
        }
    }
    if(count == 0){
        return -2;
    } else {
        return count;
    }
}

void printPattern(int num) {
    int n = num;
    char print = '*';
    for(int i = 1; i <= num; i++){
        if(i % 2 == 1){
            for(int j = 0; j < i; j++){
                cout << print;
            }
            cout << endl;
            print = '+';
        } else {
            for(int j = 0; j < i; j++){
                cout << print;
            }
            cout << endl;
            print = '*';
        }
    }
}
*/ 

void printAbnormalBloodPressure(string names[], int pressures[], int size){
    for(int i = 0; i < size; i++){
        if(pressures[i] > 120 || pressures[i] < 90){
            cout << names[i] << " " << pressures[i] << endl;
        }
    }
}

int main(){
    string names[] = {"Joe", "Jack", "Amy", "Bob"};
    int pressures[] = {90, 140, 112, 87};
    printAbnormalBloodPressure(names, pressures, 4);
    return 0;
}