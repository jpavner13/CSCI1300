#include "Pokemon.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

Pokemon::Pokemon(){
    hp = 100;
    evolution = 1;
    battles_num = 0;
}

Pokemon::Pokemon(string n, int h, int e, string t, int b){
    name = n;
    hp = h;
    evolution = e;
    type = t;
    battles_num = b;
}

void Pokemon::set_name(string n){
    name = n;
}

void Pokemon::set_hp(int hitPoints){
    hp = hitPoints;
}

void Pokemon::set_evolution(int ev){
    evolution = ev;
}

void Pokemon::set_type(string t){
    type = t;
}

void Pokemon::set_battles_num(int num){
    battles_num = num;
}

string Pokemon::get_name(){
    return name;
}

int Pokemon::get_hp(){
    return hp;
}

int Pokemon::get_evolution(){
    return evolution;
}

string Pokemon::get_type(){
    return type;
}

int Pokemon::get_battles_num(){
    return battles_num;
}

void Pokemon::inc_hp(){
    hp++;
}

void Pokemon::dec_hp(){
    hp--;
}

void Pokemon::modify_hp_by(int num){
    for(int i = 0; i < abs(num); i++){
        if(num > 0){
            inc_hp();
        } else {
            dec_hp();
        }
    }
}

void Pokemon::display() const{
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Evolution: " << evolution << endl;
    cout << "Type: " << type << endl;
}

bool Pokemon::battle(Pokemon b){
    if(hp > b.hp && battles_num > b.battles_num){
        return 0;
    } else {
        return 1;
    }
}

void Pokemon::check_evolution(){
    if(battles_num >= 10 && battles_num < 20){
        evolution = 2;
    } else if(battles_num >= 20 && battles_num < 30){
        evolution = 3;
    } else if(battles_num >= 30){
        evolution = 4;
    }
}