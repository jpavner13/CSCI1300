#include <iostream>
#include <vector>
using namespace std;

void fillCumulativeSumIterative(int stopNum){
    if(stopNum > 0){
        vector<int> sumVec{1};
        int current = 0;

        while(current < stopNum){
            for(int i = 0; i < sumVec.size(); i++){
                current += sumVec[i];
            }
            if(current < stopNum){
                sumVec.push_back(current);
                current = 0;
            }
        }
        for(int i = 0; i < sumVec.size(); i++){
            cout << sumVec[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid input." << endl;
    }
}

int main(){
    fillCumulativeSumIterative(10);
}