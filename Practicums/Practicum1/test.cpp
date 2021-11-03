#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int cars;
    double fee, registration;

    double cost;

    cout << "Enter the base cost of registration:" << endl;
    cin >> registration;
    cout << "Enter the number of cars:" << endl;
    cin >> cars;
    cout << "Enter the cost per car:" << endl;
    cin >> fee;

    if(cars >= 3 ){
        cost = registration + (fee * cars * .75);
    } else {
        cost = registration + (fee * cars);
    }

    cout << "The final cost of registration is: " << fixed << setprecision(2) << cost << endl;

    return 0;
}