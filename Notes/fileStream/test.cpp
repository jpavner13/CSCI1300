#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file;
    file.open("file.txt");

    if(file.is_open()){
        cout << "File opened successfuly!" << endl;
        string str;
        while(getline(file, str)){
            if(str.length() >= 1){
                cout << str << endl;
            }
        }
        file.close();
    } else {
        cout << "Error opening file" << endl;
    }
    return 0;
}