#include <iostream>
#include <fstream>
using namespace std;

void printInvertLine(string s){
    string str = s;
    int counter = s.length() - 1;
    for(int i = 0; i < s.length() - 1; i++){
        str[i] = s[counter];
        counter--;
    }
    cout << str << endl;
}

int main(){
    ifstream file;
    cout << "File image to invert: " << endl;
    string fileName;
    cin >> fileName;
    file.open("Images/" + fileName);
    if(file.is_open()){
        string str;
        while(getline(file, str)){
            printInvertLine(str);
        }
    } else {
        cout << "Invalad file" << endl;
    }
    return 0;
}