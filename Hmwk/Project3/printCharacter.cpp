#include <iostream>
#include <fstream>
using namespace std;

void printCharacter(){
    ifstream file;
    file.open("Character.txt");
    string str;

    while(getline(file, str)){
        cout << str << endl;
    }
}

int main(){
    system("clear");
    printCharacter();
}