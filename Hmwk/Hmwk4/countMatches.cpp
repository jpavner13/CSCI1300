// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 4 - Problem #4

#include <iostream>
using namespace std;

int main(){
    string str, search;
    cout << "Enter the search string:" << endl;
    cin >> str;
    cout << "Enter the substring to be searched:" << endl;
    cin >> search;

    int count = 0;

    for(int i = (str.length() - (search.length() - 1)); i >= 0 ; i--){
        string sub = str.substr(i, search.length());
        if(sub == search){
            count ++;
        }
    }
    cout << "Number of occurrences: " << count << endl;
    return 0;
}