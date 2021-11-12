#include <iostream>
#include "Fighter.h"
using namespace std;

class Player{
    public:
        Player();
        Player(string name, string password);

        string getPlayerName();
        int setPlayerName(string newName);

        string getPlayerPassword();
        int setPlayerPassword(string newPassword);

        int getPlayerAccountBalance();
        int setPlayerAccountBalance(int newBalance);

        Fighter getPlayerFighterAt(int index);
        int addPLayerFighter(Fighter newFighter);

        int getNumberOfFighters();
        int incrementNumOfFighters();

    private:
        string playerName;
        string playerPassword;
        int playerAccountBalance;
        Fighter fighters[10];
        int numOfFighters;
};