#include <iostream>
using namespace std;

int main(){
    int initialMoney = 0;
    cout << "What is your budget in dollars?" << endl;
    cin >> initialMoney;
    if(initialMoney < 0){
        cout << "Enter an amount that is larger than 0." << endl;
        cin >> initialMoney;
    }

    int stamps = 0;
    cout << "How many stamps would you like?" << endl;
    cin >> stamps;
    if(stamps < 0){
        cout << "Enter an amount that is larger than 0." << endl;
        cin >> stamps;
    }

    int COST = 55;
    int change = 0;

    int purchacePrice = stamps * COST;
    if(purchacePrice > (initialMoney * 100)){
        cout << "Not enough money" << endl;
    } else {
        cout << "Vending...." << endl;
        change = (initialMoney * 100) - purchacePrice;
        cout << "Change = " << (change / 100) << " Dollars and " << (change % 100) << " cents." << endl;
    }

    return 0;
}