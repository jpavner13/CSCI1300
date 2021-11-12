#include <iostream>
#include "Menu.h"
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