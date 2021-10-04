#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Example: Buying breakfast

    char option;
    cout << "What would you like to buy today?"  << endl;
    cout << "a: Apple-------------------$2.99" << endl;
    cout << "b: Bagel-------------------$5.99" << endl;
    cout << "c: Cinnamon roll-----------$4.99" << endl;
    cout << "d: Doughnut----------------$3.99" << endl;
    cout << "q: Quit" << endl;
    cin >> option;

        while(option != 'q'){
                switch(option)
                {   
                        case 'a': 
                                cout << "You bought an Apple" << endl;
                                break; 
                        case 'b': 
                                cout << "You bought a Bagel" << endl;
                                break;
                        case 'c':
                                cout << "You bought a Cinnamon roll" << endl;
                                break;
                        case 'd': 
                                cout << "You bought a doughnut" << endl;
                                break;
                        case 'q': 
                                cout << "Goodbye! Have a nice day!!" << endl;
                                break;
                        default: 
                                cout << "Sorry! We don't have that item in our menu" << endl;
                                break;
                } while (option != 'q');
        }
    return 0;
}