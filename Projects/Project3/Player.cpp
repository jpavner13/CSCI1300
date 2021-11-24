#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(){

}
Player::Player(string name, string password, int balance, int fighters){
    playerName = name;
    playerPassword = password;
    playerAccountBalance = balance;
    numOfFighters = fighters;
}
string Player::getPlayerName(){
    return playerName;
}
int Player::setPlayerName(string newName){
    playerName = newName;
    return 0;
}
string Player::getPlayerPassword(){
    return playerPassword;
}
int Player::setPlayerPassword(string newPassword){
    playerPassword = newPassword;
    return 0;
}
int Player::getPlayerAccountBalance(){
    return playerAccountBalance;
}
int Player::setPlayerAccountBalance(int newBalance){
    playerAccountBalance = newBalance;
    return 0;
}
Fighter Player::getPlayerFighterAt(int index){
    return fighters[index];
}
int Player::addPLayerFighter(Fighter newFighter){
    fighters[numOfFighters] = newFighter;
    return 0;
}
int Player::getNumberOfFighters(){
    return numOfFighters;
}
int Player::incrementNumOfFighters(){
    numOfFighters++;
    return 0;
}
int Player::decrementNumberOfFighters(){
    numOfFighters--;
    return 0;
}