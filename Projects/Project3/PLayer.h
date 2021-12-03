#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Fighter.h"
using namespace std;

class Player{
    public:
        Player();
        Player(string name, string password, int balance, int fighters);

        string getPlayerName();
        int setPlayerName(string newName);

        string getPlayerPassword();
        int setPlayerPassword(string newPassword);

        int getPlayerAccountBalance();
        int setPlayerAccountBalance(int newBalance);

        Fighter getPlayerFighterAt(int index);
        int addPLayerFighterAt(Fighter, int);
        int addPLayerFighter(Fighter newFighter);

        int getNumberOfFighters();
        int incrementNumOfFighters();
        int setNumberOfFighters(int);
        int decrementNumberOfFighters();

    private:
        string playerName;
        string playerPassword;
        int playerAccountBalance;
        Fighter fighters[10];
        int numOfFighters;
};

#endif