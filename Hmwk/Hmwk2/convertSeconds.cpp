// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 2 - Problem #7

#include <iostream>
using namespace std;

int main(){                                                         //Initialize main function
    int seconds;                                                    //Initialize seconds
    cout << "Enter a number of seconds:" << endl;                   //Print "Enter seconds"
    cin >> seconds;                                                 //Set input to seconds

    int hour, min;                                                  //Initialize hour and min
    hour = seconds / 3600;                                          //get hours
    min = (seconds % 3600) / 60;                                    //Get min
    seconds -= ((hour * 3600) + (min * 60));                        //get remainder seconds
    cout << hour << " hour(s) " << min << " minute(s) " << seconds << " second(s)" << endl;     //Print output
    return 0;                                                       //Return data type
}