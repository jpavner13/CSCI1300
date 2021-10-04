#include <iostream>
#include <cmath> // Allows you to use more advanced math: pow(base, exp), etc.

using namespace std;

int main(){
    int a;

    cout << "Enter an integer: ";
    cin >> a; // cin >> a >> b >> c
    cout << "The value entered by the user cubed is: " << pow(a, 3) << endl;

    cout << "End of program" << endl;
    return 0;
}