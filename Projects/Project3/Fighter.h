#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>
using namespace std;

class Fighter{
    public:
        Fighter();
        Fighter(string newFighterName, int startHp, int startPower, int startLevel, int startFightsWon, int startTotalFights, int startPrice);

        string getFighterName();
        int setFighterName(string newName);

        int getHp();
        int setHp(int newHp);

        int getPower();
        int setPower(int newPower);

        int getLevel();
        int setLevel(int newLevel);

        int getFightsWon();
        int incrementFightsWon();

        int getTotalFights();
        int incrementTotalFights();

        int getPrice();
        int setPrice(int price);

    private:
        string fighterName;
        int hp;
        int power;
        int level;
        int fightsWon;
        int totalFights;
        int price;
};
#endif