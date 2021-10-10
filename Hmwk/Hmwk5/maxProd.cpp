// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 5 - Problem #4

#include <iostream>
using namespace std;

int maxProd(int matrix[][10], int rows){
    int prod = 1;
    for(int i = 0; i < rows; i++){
        int max = -9999999;
        for(int j = 0; j < 10; j++){
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
        prod = prod * max;
    }
    return prod;
}

int main(){

}