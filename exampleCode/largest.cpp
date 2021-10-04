#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Enter three positive numbers: " << endl;
    cin >> a >> b >> c;

    int max = a;

    if(b > max){
        max = b;
    }
    if(c > max){
        max = c;
    }
    
    cout << "Max value is: " << max << endl;
    return 0;
}