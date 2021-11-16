#include <iostream>
#include "GroceryList.h"
#include <fstream>
using namespace std;

GroceryList::GroceryList(){
    for(int i = 0; i < 50; i++){
        groceries[i] = "";
        codes[i] = "";
    }
}

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

int GroceryList::loadGroceryItems(string filename){
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string str;
        int i = 0;
        while(getline(file, str)){
            string s[2];
            split(str, ',', s, 2);
            groceries[i] = s[0];
            codes[i] = s[1];
            i++;
        }
        return 0;
    } else {
        return -1;
    }
}
int GroceryList::searchForCodes(string groceryCode){
    for(int i = 0; i < 50; i++){
        if(codes[i] == groceryCode){
            return i;
        }
    }
    return -1;
}
string GroceryList::getGroceryItem(string groceryCode){
    for(int i = 0; i < 50; i++){
        if(codes[i] == groceryCode){
            return groceries[i];
        }
    }
    return "";
}