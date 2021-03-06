#include <iostream>
#include "Menu.h"
#include <unistd.h>
#include <fstream>
using namespace std;

Menu::Menu(){}
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

/*
    prints options from text file
    returns users choice from those options
*/

int Menu::getChoice(){
    int choice;
    ifstream file;
    file.open("Images/getOption.txt");
    string str;
    while(getline(file, str)){
        cout << str << endl;
    }
    cin >> choice;
    return choice;
}

/*
    prints text file with menu
*/

void Menu::printMenu(){
    system("clear");
    ifstream file;
    string str;
    file.open("Images/Title.txt");
    while(getline(file, str)){
        cout << str << endl;
    }
    file.close();
}

/*
    prints text file with asking name line
*/

void Menu::askName(){
    ifstream file;
    file.open("Images/enterName.txt");
    string str;
    while(getline(file, str)){
        cout << str << endl;
    }
    file.close();
}

/*
    prints text file with asking password line
*/

void Menu::askPassword(){
    ifstream file;
    file.open("Images/enterPassword.txt");
    string str;
    while(getline(file, str)){
        cout << str << endl;
    }
    file.close();
}

/*
    prints text file with user does not exist line
*/

void Menu::userExists(){
    ifstream file;
    file.open("Images/userExists.txt");
    string str;
    while(getline(file, str)){
        cout << str << endl;
    }
    file.close();
}

/*
    prints text file with welcome info
*/

void Menu::welcome(){
    ifstream file;
    file.open("Images/Welcome.txt");
    string str;
    while(getline(file, str)){
        cout << str << endl;
    }
    file.close();
}

/*
    prints text file with Shop options
*/

void Menu::printFighterShop(){
    ifstream file;
    file.open("FighterShop.txt");
    string str;
    while(getline(file, str)){
        cout << str << endl;
    }
    file.close();
}

/*
    prints text file with Shop title
*/

void Menu::printShopTitle(){
    ifstream file;
    file.open("Images/ShopTitle.txt");
    string str;
    while(getline(file, str)){
        cout << str << endl;
    }
    file.close(); 
}