// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #6

/*  
    PSUDO CODE:
        1. Include Listener.h
        2. Test initialization
        3. Test all functions and print outputs to make sure they work correctly
*/

#include "Listener.h"
#include <iostream>
using namespace std;

int main(){
    int plays[50];
    for(int i = 0; i < 50; i++){
        plays[i] = i;
    }

    Listener listener1 = Listener("Bill", plays, 50);
    Listener listener2 = Listener();

    cout << listener1.getListenerName() << endl;
    listener2.setListenerName("Will");
    cout << listener2.getListenerName() << endl;
    cout << listener1.readListenerInfo() << endl;
    cout << listener2.readListenerInfo() << endl;
    cout << listener1.getPlayCountAt(25) << endl;
    cout << listener2.getPlayCountAt(25) << endl;
    return 0;
}