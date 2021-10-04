#include <iostream>
using namespace std;

int main(){
    char option;
    cout << "Menu:" << endl;
    cout << "a = Apple" << endl;
    cout << "b = Bagel" << endl;
    cout << "c = Cinnimon roll" << endl;
    cout << "d = doughnut" << endl;
    cout << "q = Quit" << endl;
    cout << "What would you like to buy?" << endl;
    cin >> option;

    switch(option){
        case 'a': cout << "You bouught an apple" << endl; break;
        case 'b': cout << "You bouught a bagel" << endl; break;
        case 'c': cout << "You bouught a Cinnimon roll" << endl; break;
        case 'd': cout << "You bouught a doughnut" << endl; break;
        case 'q': cout << "You Quit" << endl; break;
        default: cout << "Invalid input" << endl; break;
    }
}