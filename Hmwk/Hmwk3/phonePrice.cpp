// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 3 - Problem #5

#include <iostream>
using namespace std;

int main(){
    int brand;
    int year;
    int storage;

    cout << "Enter Type of Phone : 1.Apple 2.Samsung" << endl;
    cin >> brand;
    switch(brand){
        case 1:
            cout << "Enter Year Made : 1.Before 2015 2.After 2015" << endl;
            cin >> year;
            if (year == 2){
                cout << "Enter Storage Capacity : 1.64GB 2.128GB 3.256GB" << endl;
                cin >> storage;
                if(storage == 1){
                    cout << "Price of the phone is $140." << endl;
                } else if(storage == 2){
                    cout << "Price of the phone is $190." << endl;
                } else if(storage == 3){
                    cout << "Price of the phone is $250." << endl;
                } else {
                    cout << "Invalid Input." << endl;
                }
            } else if (year == 1){
                cout << "Enter Storage Capacity : 1.32GB 2.64GB" << endl;
                cin >> storage;
                if(storage == 1){
                    cout << "Price of the phone is $80." << endl;
                } else if(storage == 2){
                    cout << "Price of the phone is $120." << endl;
                } else {
                    cout << "Invalid Input." << endl;
                }
            } else {
                cout << "Invalid Input." << endl;
            }
            break;
        case 2:
            cout << "Enter Year Made : 1.Before 2017 2.After 2017" << endl;
            cin >> year;
            if (year == 1){
                cout << "Enter Storage Capacity : 1.32GB 2.64GB 3.128GB" << endl;
                cin >> storage;
                if(storage == 1){
                    cout << "Price of the phone is $90." << endl;
                } else if(storage == 2){
                    cout << "Price of the phone is $125." << endl;
                } else if(storage == 3){
                    cout << "Price of the phone is $165." << endl;
                } else {
                    cout << "Invalid Input." << endl;
                }
            } else if(year == 2) {
                cout << "Enter Storage Capacity : 1.128GB 2.256GB" << endl;
                cin >> storage;
                if(storage == 1){
                    cout << "Price of the phone is $220." << endl;
                } else if(storage == 2){
                    cout << "Price of the phone is $260." << endl;
                } else {
                    cout << "Invalid Input." << endl;
                }
            } else {
                cout << "Invalid Input." << endl;
            }
            break;
        default:
            cout << "Invalid Input." << endl;
            break;
    }
    return 0;
}