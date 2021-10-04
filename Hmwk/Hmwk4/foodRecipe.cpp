// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 4 - Problem #3

#include <iostream>

using namespace std;

void printMenu(){
    cout << "Select a numerical option:" << endl << "=== menu ===" << endl << "1. BLT" << endl <<
     "2. Caprese" << endl << "3. Veggie" << endl << "4. Quit" << endl;
}

int main(){
    int input;
    bool inLoop = true;

    while(inLoop){
        printMenu();
        cin >> input;
        switch(input){
            case 1:
                double bacon, lettuce, tomato, mayo;
                cout << "How many bacon strips do you have?" << endl;
                cin >> bacon;
                cout << "How many tomato slices do you have?" << endl;
                cin >> tomato;
                cout << "How many lettuce leaves do you have?" << endl;
                cin >> lettuce;
                cout << "How many ounces of mayonnaise do you have?" << endl;
                cin >> mayo;

                if((bacon >= 4) && (tomato >= 3) && (lettuce >= 2) && (mayo >= 0.51)){
                    cout << "You can make a BLT." << endl;
                } else {
                    cout << "You don't have enough for a BLT." << endl;
                }
                break;
            case 2:
                double mozz, basil, tomat, balsamic;
                cout << "How many mozzarella slices do you have?" << endl;
                cin >> mozz;
                cout << "How many tomato slices do you have?" << endl;
                cin >> tomat;
                cout << "How many basil leaves do you have?" << endl;
                cin >> basil;
                cout << "How many ounces of balsamic glaze do you have?" << endl;
                cin >> balsamic;

                if((mozz >= 4) && (tomat >= 2) && (basil >= 9) && (balsamic >= 0.12)){
                    cout << "You can make a caprese sandwich." << endl;
                } else {
                    cout << "You don't have enough for a caprese sandwich." << endl;
                }
                break;
            case 3:
                double redOnion, cucumber, pepper, hummus;
                cout << "How many red onion rings do you have?" << endl;
                cin >> redOnion;
                cout << "How many cucumber slices do you have?" << endl;
                cin >> cucumber;
                cout << "How many ounces of diced roasted pepper do you have?" << endl;
                cin >> pepper;
                cout << "How many ounces of hummus do you have?" << endl;
                cin >> hummus;

                if((redOnion >= 5) && (cucumber >= 7) && (pepper >= 2.33) && (hummus >= 2.5)){
                    cout << "You can make a veggie sandwich." << endl;
                } else {
                    cout << "You don't have enough for a veggie sandwich." << endl;
                }
                break;
            case 4:
            cout << "Goodbye!" << endl;
                inLoop = false;
                break;
            default:
                cout << "Invalid input." << endl;

        }
    }
    return 0;
}