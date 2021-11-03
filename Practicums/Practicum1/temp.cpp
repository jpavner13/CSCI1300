#include <iostream>
using namespace std;

int main(){
    int temp1, temp2, temp3;
    cout << "Enter the temperature of the first area:" << endl;
    cin >> temp1;
    cout << "Enter the temperature of the second area:" << endl;
    cin >> temp2;
    cout << "Enter the temperature of the third area:" << endl;
    cin >> temp3;

    int low;

    if ((temp1 <= temp2) && (temp1 <= temp3)){
        low = temp1;
    } else if((temp2 <= temp1) && (temp2 <= temp3)){
        low = temp2;
    } else {
        low = temp3;
    }
    cout << "The lowest temperature in the list of areas is " << low << endl;
    return 0;
}