#include <iostream>
using namespace std;
// program to print the first 10 numbers beginning at 1

int main(){
    cout << "1" << endl;
    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;
    cout << "5" << endl;
    cout << "6" << endl;
    cout << "7" << endl;
    cout << "8" << endl;
    cout << "9" << endl;
    cout << "10" << endl;

    int num = 1; // variable used for the loop condition is defined outside of the loop

    while(num <= 10) // the following block of code will be executed as long as the condition for the while loop remains true
    {
        cout << num << endl;
        num++;
    }
    return 0;
}