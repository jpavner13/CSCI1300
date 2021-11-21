#include <iostream>
#include "Menu.h"
#include <unistd.h>
using namespace std;

Menu::Menu(){

}
string Menu::getMenuOptionAt(int index){
    return options[index];
    return 0;
}
int Menu::setMenuOptionNameAt(int index, string optionName){
    options[index] = optionName;
    return 0;
}
string Menu::getGameName(){
    return gameName;
    return 0;
}
int Menu::setGameName(string newGameName){
    gameName = newGameName;
    return 0;
}

int Menu::getChoice(){
    int choice;
    cout << "Enter an option from above:" << endl;
    cin >> choice;
    return choice;
}

void Menu::printMenu(){
    system("clear");
    cout << gameName << endl;
    for(int i = 0; i < numOptions; i++){
        cout << (i + 1) << ": " << options[i] << endl;;
    }
}