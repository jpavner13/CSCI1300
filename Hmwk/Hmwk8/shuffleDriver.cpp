// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 8 - Problem #2

#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int> vec1, vector<int> vec2){
    vector<int> firstVector;
    vector<int> secondVector;
    if(vec2.size() > vec1.size()){
        for(int i = vec2.size() - 1; i >= 0; i--){
            firstVector.push_back(vec2[i]);
        }
        for(int i = vec1.size() - 1; i >= 0; i--){
            secondVector.push_back(vec1[i]);
        }
    } else {
        for(int i = vec1.size() - 1; i >= 0; i--){
            firstVector.push_back(vec1[i]);
        }
        for(int i = vec2.size() - 1; i >= 0; i--){
            secondVector.push_back(vec2[i]);
        }
    }

    vector<int> returnVec;
    for(int i = 0; i < firstVector.size(); i++){
        if(i < secondVector.size()){
            returnVec.push_back(firstVector[i]);
            returnVec.push_back(secondVector[i]);
        } else {
            returnVec.push_back(firstVector[i]);
        }
    }

    return returnVec;
}

int main(){
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{6, 7, 8, 9, 10};

    shuffle(v1, v2);
}