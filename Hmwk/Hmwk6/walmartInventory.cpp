// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 6 - Problem #1

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file;
    string fileName;
    cout << "Enter the file name:" << endl;
    cin >> fileName;
    file.open(fileName);

    if(file.is_open()){
        double maxPrice = 0.0;
        double minPrice = 9999999.99;
        string maxName = "";
        string minName = "";
        string str;
        int countLines = 0;
        while(getline(file, str)){
            if(str.length() != 0){
                int index = str.find(",");
                string name = str.substr(0, index);
                string priceString = str.substr((index + 2), (str.length() - (index + 2)));
                double priceInt = stod(priceString);
                if(priceInt > maxPrice){
                    maxPrice = priceInt;
                    maxName = name;
                }
                if (priceInt < minPrice){
                    minPrice = priceInt;
                    minName = name;
                }
                countLines++;
            }
        }
        cout << "The number of lines: " << countLines << endl;
        cout << "The most expensive product: " << maxName << endl;
        cout << "The least expensive product: " << minName << endl;
        file.close();
    } else {
        cout << "Could not open file." << endl;
    }
    return 0;
}