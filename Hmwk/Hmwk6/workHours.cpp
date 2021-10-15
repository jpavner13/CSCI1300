#include <iostream>
#include <fstream>
#include <sstream>
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
    int countNames = 0;
    int countLine = 0;
    if(file.is_open()){
        string str;
        bool oddLine = true;
        int row = -1;
        while(getline(file, str)){
            if(str.length() != 0){
                if(oddLine){
                    row++;
                    names[row] = str;
                    oddLine = false;
                    countNames++;
                } else {
                    string nums[12];
                    split(str, ',', nums, 12);
                    for(int i = 0; i < 12; i++){
                        string intStr = nums[i];
                        stringstream geek(intStr);
                        int currentInt;
                        geek >> currentInt;
                        hours[row][i] = currentInt;
                    }
                    oddLine = true;
                }
            }
            if(countLine > (namesLength * 2)){
                break;
            }
            countLine++;
        }
        file.close();
    } else {
        return -1;
    }
    for(int i = 0; i < countNames; i++){
        int total = 0;
        for(int x = 0; x < 12; x++){
            total += (hours[i][x]);
        }
        double avg = double(total) / 12.0;
        cout << names[i] << ": " << fixed << setprecision(1) << avg << endl;
    }
    return countNames;
}

int main(){
    string names[3];
    int hours[3][12];
    workHours("hours.txt", names, hours, 3);
    return 0;
}