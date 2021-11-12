#include <iostream>
#include "Fighter.h"
using namespace std;

Fighter::Fighter(){
    fighterName = "";
}

Fighter:: Fighter(string newFighterName, int startHp, int startPower){
    fighterName = newFighterName;
    hp = startHp;
    power = startPower;
}

string Fighter::getFighterName(){
    return fighterName;
}

int Fighter::setFighterName(string newName){
    if(newName.length() != 0){
        fighterName = newName;
        return 0;
    } else {
        return -1;
    }
    return 0;
}

int Fighter::getHp(){
    return hp;
}

int Fighter::setHp(int newHp){
    if(newHp > 0){
        hp = newHp;
        return 0;
    } else {
        return -1;
    }
    return 0;
}

int Fighter::getPower(){
    return power;
}

int Fighter::setPower(int newPower){
    power = newPower;
    return 0;
}

int Fighter::getLevel(){
    return level;
}

int Fighter::setLevel(int newLevel){
    level = newLevel;
    return 0;
}

int Fighter::getFightsWon(){
    return fightsWon;
}

int Fighter::incrementFightsWon(){
    fightsWon++;
    return 0;
}

int Fighter::getTotalFights(){
    return totalFights;
}

int Fighter::incrementTotalFights(){
    totalFights++;
    return 0;
}

int Fighter::getPrice(){
    return price;
}

int Fighter::setPrice(int newPrice){
    price = newPrice;  
    return 0;
}