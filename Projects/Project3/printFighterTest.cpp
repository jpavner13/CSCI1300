#include <iostream>
#include <fstream>
using namespace std;

void printInvertLine(string s){
    string str = "                                                           ";
    int counter = s.length() - 1;
    for(int i = 0; i < s.length() - 1; i++){
        str[i] = s[counter];
        counter--;
    }
    cout << str << endl;
}

int main(){
    ifstream fighter;
    ifstream fighter2;
    fighter.open("fighter.txt");
    fighter2.open("fighter2.txt");
    string str;
    string s2;
    int i = 1;
    while(getline(fighter, str)){
        getline(fighter2, s2) >> s2;
        cout << str;
        cout << "                          ";
        cout << s2 << endl;
        i++;
    }
}
