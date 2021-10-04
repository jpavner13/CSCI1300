#include <iostream>
using namespace std;

int main(){
    string name;

    cout << "What is your name?" << endl;
    //cin >> name;                                      //saves just one word: Pierce avner would just store "Pierce"
    getline(cin, name);                                 //another option on how to get inputs with spaces: Pierce Avner
    cout << "Your name is " << name << endl;

    return 0;
}