#include <iostream>

using namespace std;

int main(){
    char firstLetter;

    cout << "Enter the first letter of the Car Company:" << endl;
    cin >> firstLetter;

    switch(firstLetter){
        case 'T':
            cout << "Car Chosen: Tata" << endl;
            break;
        case 'A':
            cout << "Car Chosen: Alfa Romeo" << endl;
            break;
        case 'B':
            cout << "Car Chosen: Bentley" << endl;
            break;
        case 'V':
            cout << "Car Chosen: Volvo" << endl;
            break;
        default:
            cout << "Car Chosen: Invalid" << endl;
            break;
    }
    return 0;
}