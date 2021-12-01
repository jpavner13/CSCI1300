#ifndef RING_H
#define RING_H

#include <iostream>

using namespace std;

class Ring{
    public:
        Ring();

        int getPlayer1XPos();
        int getPlayer1YPos();
        int getPlayer2XPos();
        int getPlayer2YPos();
        int getPowerUpXPos();
        int getPowerUpYPos();

        int setPlayer1Pos(int, int);
        int setPlayer2Pos(int, int);
        int setPowerUpPos(int, int);

        void displayRing();

        void displayMoves(int);

        void makeMove(int, char);

        bool playersCollide();
        bool powerUpCollide1();
        bool powerUpCollide2();

    private:
        int player1Pos[2];
        int player2Pos[2];
        int powerUpPos[2] = {14,0};

        string ringData[15][15];
};

#endif