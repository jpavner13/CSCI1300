// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 8 - Problem #4

#include <iostream>
#include <vector>
using namespace std;

int getNextNumber(vector<int> numVect){
    if (numVect.size() <= 1){
        return numVect[0];
    }
    else {
        vector<int> slice(numVect.begin() + 1, numVect.begin() + numVect.size());
        return numVect[0] + getNextNumber(slice);
    }
}

vector<int> vec{1};

void printVector(int count){
    if(vec.size() > count){
        cout << vec[count] << " ";
        count++;
        printVector(count);
    }
}

void fillCumulativeSumRecursive(int lastNum){
    if(lastNum > 0){
        if(lastNum > getNextNumber(vec)){
            vec.push_back(getNextNumber(vec));
            fillCumulativeSumRecursive(lastNum);
        } else {
            int count = 0;
            printVector(count);
            cout << endl;
        }
    } else {
        cout << "Invalid input." << endl;
    }
}

int main(){
    fillCumulativeSumRecursive(20);
    return 0;
}