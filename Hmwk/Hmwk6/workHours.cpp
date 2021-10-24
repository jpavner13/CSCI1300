// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 6 - Problem #2

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int split(string str, char sep, string arr[], int arrSize){
    string current = "";
    int count = 1;
    if(str.length() < 1){
        count = 0;
    }
    int arrCurrent = 0;
    int length = str.length();
    for(int i = 0; i < length; i++){
        if(str[i] == sep){
            arr[arrCurrent] = current;
            current = "";
            arrCurrent++;
            count++;
        } else {
            current += str[i];
        }
    }
    if(arrSize < count){
        count = -1;
    }
    arr[arrCurrent] = current;
    return count;
}

int workHours(string fileName, string names[], int hours[][12], int namesLength){
    ifstream file;
    file.open(fileName);
    if(file.is_open()){
        string namesPlace[namesLength];
        for(int i = 0; i < namesLength; i++){
            namesPlace[i] = names[i];
        }
        int countNames = 0;
        string str;
        int countLines = 0;
        int nameIndex = 0;
        bool isOdd = true;
        bool namesIsDone = false;
        bool end = false;
        int len = sizeof(namesPlace) / sizeof(namesPlace[0]);
        //cout << len << endl;
        while(getline(file, str)){
            if(end){
                if(countNames < len){
                    end = true;
                }
                if(isOdd){
                    names[nameIndex] = str;
                    nameIndex++;
                    countNames++;
                    isOdd = false;
                    //cout << str << endl;
                } else {
                string nums[12];
                int currentHours[12];
                split(str, ',', nums, 12);
                bool isFirstNum = true;
                for(int i = 0; i < 12; i++){
                    string s = nums[i];
                    string numString;
                    if(isFirstNum){
                        numString = s;
                        isFirstNum = false;
                    } else {
                        numString = s.substr(1, (s.length() - 1));
                    }
                    double currentHour = stod(numString);
                    currentHours[i] = currentHour;
                    for(int i = 0; i < 12; i++){
                        hours[countNames - 1][i] = currentHours[i];
                    }
                }
                isOdd = true;
            }
        }
        }
        for(int i = 0; i < namesLength; i++){
            string currentName = names[i];
            int currentTotal = 0;
            for(int x = 0; x < 12; x++){
                currentTotal += hours[i][x];
                //cout << hours[i][x] << " ";
            }
            double avg = double(currentTotal) / 12.0;
            cout << currentName << ": " << fixed << setprecision(1) << avg << endl;
        }
        return countNames;
    } else {
        return -1;
    }
    file.close();
}

int main(){
    string names[4];
    int hours[4][12];
    workHours("hours.txt", names, hours, 4);
    return 0;
}