#include <iostream>
using namespace std;

// program to check if a number is positive, negative or zero

int main()
{
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;

    if(num == 0){
        cout << "Number is 0" << endl;
    } else if (num < 0){
        cout << "Number is nagitive" << endl;
    } else if (num > 0){
        cout << "Number is positive" << endl;
    } else {
        cout << "Not a valid input" << endl;
    }


    return 0;
}