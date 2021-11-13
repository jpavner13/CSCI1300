#include <iostream>
#include <vector>
using namespace std;

int getNextNumber(vector<int> vec, int counter){
    if(counter >= vec.size()){
        return vec[counter];
    }
    return vec[counter] + getNextNumber(vec, counter + 1);
}

void fillCumulativeSumRecursive(int stopNum){
    vector<int> vec{1};
    cout << vec.size() << endl;
    if(stopNum >= getNextNumber(vec, 0)){
        int i = getNextNumber(vec, 0);
        cout << i << endl;
        cout << i << " ";
        vec.push_back(i);
    }
    cout << endl;
}

int main(){
    fillCumulativeSumRecursive(20);
    return 0;
}