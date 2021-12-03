#include "Ring.h"
#include <unistd.h>

using namespace std;

/*
    This is my edit of the Map class
    Map class was too specifit to the assigned game and needed quite a bit of modificaton for my own game
    Most functions have the same functionality apart from name changes and Character changes
    This class is more applicable to my game
*/

Ring::Ring(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            ringData[i][j] = " - ";
        }
    }
    player1Pos[0] = 0;
    player1Pos[1] = 0;
    ringData[0][0] = " X ";
    player2Pos[0] = 14;
    player2Pos[1] = 14;
    ringData[14][14] = " O ";
}

int Ring::getPlayer1XPos(){
    return player1Pos[0];
}
int Ring::getPlayer1YPos(){
    return player1Pos[1];
}
int Ring::getPlayer2XPos(){
    return player2Pos[0];
}
int Ring::getPlayer2YPos(){
    return player2Pos[1];
}
int Ring::getPowerUpXPos(){
    return powerUpPos[0];
}
int Ring::getPowerUpYPos(){
    return powerUpPos[1];
}

int Ring::setPlayer1Pos(int x, int y){
    ringData[player1Pos[0]][player1Pos[1]] = " - ";
    player1Pos[0] = x;
    player1Pos[1] = y;
    ringData[x][y] = " X ";
    return 0;
}
int Ring::setPlayer2Pos(int x, int y){
    ringData[player2Pos[0]][player2Pos[1]] = " - ";
    player2Pos[0] = x;
    player2Pos[1] = y;
    ringData[x][y] = " O ";
    return 0;
}
int Ring::setPowerUpPos(int x, int y){
    ringData[powerUpPos[0]][powerUpPos[1]] = " - ";
    powerUpPos[0] = x;
    powerUpPos[1] = y;
    ringData[x][y] = " ? ";
    return 0;
}

void Ring::displayRing(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            cout << ringData[i][j];
        }
        cout << endl;
    }
}

void Ring::displayMoves(int player){
    if(player == 1){
        cout << "Player 1 Moves:" << endl;
        if(player1Pos[0] > 0){
            cout << "w: move up" << endl;
        }
        if(player1Pos[1] > 0){
            cout << "a: move left" << endl;
        }
        if(player1Pos[0] < 14){
            cout << "s: move down" << endl;
        }
        if(player1Pos[1] < 14){
            cout << "d: move right" << endl;
        }
    } else {
        cout << "Player 2 Moves:" << endl;
        if(player2Pos[0] > 0){
            cout << "w: move up" << endl;
        }
        if(player2Pos[1] > 0){
            cout << "a: move left" << endl;
        }
        if(player2Pos[0] < 14){
            cout << "s: move down" << endl;
        }
        if(player2Pos[1] < 14){
            cout << "d: move right" << endl;
        }
    }
}

void Ring::makeMove(int player, char direction){
    if(player == 1){
        if(direction == 'w' && player1Pos[0] > 0){
            ringData[player1Pos[0]][player1Pos[1]] = " - ";
            player1Pos[0] = (player1Pos[0] - 1);
            ringData[player1Pos[0]][player1Pos[1]] = " X ";
            return;
        }
        if(direction == 'a' && player1Pos[1] > 0){
            ringData[player1Pos[0]][player1Pos[1]] = " - ";
            player1Pos[1] = (player1Pos[1] - 1);
            ringData[player1Pos[0]][player1Pos[1]] = " X ";
            return;
        }
        if(direction == 's' && player1Pos[0] < 14){
            ringData[player1Pos[0]][player1Pos[1]] = " - ";
            player1Pos[0] = (player1Pos[0] + 1);
            ringData[player1Pos[0]][player1Pos[1]] = " X ";
            return;
        }
        if(direction == 'd' && player1Pos[1] < 14){
            ringData[player1Pos[0]][player1Pos[1]] = " - ";
            player1Pos[1] = (player1Pos[1] + 1);
            ringData[player1Pos[0]][player1Pos[1]] = " X ";
            return;
        }
        cout << "Invlid move." << endl;
        usleep(2000000);
    } else {
        if(direction == 'w' && player2Pos[0] > 0){
            ringData[player2Pos[0]][player2Pos[1]] = " - ";
            player2Pos[0] = (player2Pos[0] - 1);
            ringData[player2Pos[0]][player2Pos[1]] = " O ";
            return;
        }
        if(direction == 'a'  && player2Pos[1] > 0 ){
            ringData[player2Pos[0]][player2Pos[1]] = " - ";
            player2Pos[1] = (player2Pos[1] - 1);
            ringData[player2Pos[0]][player2Pos[1]] = " O ";
            return;
        }
        if(direction == 's' && player2Pos[0] < 14){
            ringData[player2Pos[0]][player2Pos[1]] = " - ";
            player2Pos[0] = (player2Pos[0] + 1);
            ringData[player2Pos[0]][player2Pos[1]] = " O ";
            return;
        }
        if(direction == 'd' && player2Pos[1] < 14){
            ringData[player2Pos[0]][player2Pos[1]] = " - ";
            player2Pos[1] = (player2Pos[1] + 1);
            ringData[player2Pos[0]][player2Pos[1]] = " O ";
            return;
        }
        cout << "Invlid move." << endl;
        usleep(2000000);
    }
    displayRing();
}

bool Ring::playersCollide(){
    if((player1Pos[1] == player2Pos[1]) && (player1Pos[0] == player2Pos[0])){
        return true;
    }
    return false;
}

bool Ring::powerUpCollide1(){
    if((player1Pos[0] == powerUpPos[0]) && (player1Pos[1] == powerUpPos[1])){
        return true;
    }
    return false;
}

bool Ring::powerUpCollide2(){
    if((player2Pos[0] == powerUpPos[0]) && (player2Pos[1] == powerUpPos[1])){
        return true;
    }
    return false;
}