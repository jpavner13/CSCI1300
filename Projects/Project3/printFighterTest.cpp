#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void printPlayer1PunchPlayer2Block0(){
    ifstream fighter0;
    fighter0.open("Images/player1PunchPlayer2Block/player1PunchPlayer2Block0.txt");
    if(!fighter0.is_open()){
        cout << "Fighter 1 is not open" << endl;
    }
    string str;
    while(getline(fighter0, str)){
        cout << str << endl;
    }
    fighter0.close();
}

void printPlayer1PunchPlayer2Block1(){
    ifstream fighter1;
    fighter1.open("Images/player1PunchPlayer2Block/player1PunchPlayer2Block1.txt");
    if(!fighter1.is_open()){
        cout << "Fighter 2 is not open" << endl;
    }
    string str;
    while(getline(fighter1, str)){
        cout << str << endl;
    }
    fighter1.close();
}

void printPlayer1PunchPlayer2Block2(){
    ifstream fighter2;
    fighter2.open("Images/player1PunchPlayer2Block/player1PunchPlayer2Block2.txt");
    if(!fighter2.is_open()){
        cout << "Fighter 2 is not open" << endl;
    }
    string str;
    while(getline(fighter2, str)){
        cout << str << endl;
    }
    fighter2.close();
}

void printPlayer1PunchPlayer2Block3(){
    ifstream fighter3;
    fighter3.open("Images/player1PunchPlayer2Block/player1PunchPlayer2Block3.txt");
    if(!fighter3.is_open()){
        cout << "Fighter 3 is not open" << endl;
    }
    string str;
    while(getline(fighter3, str)){
        cout << str << endl;
    }
    fighter3.close();
}

void player1PunchPlayer2Block(){
    system("clear");
    printPlayer1PunchPlayer2Block0();
    usleep(1000000);
    system("clear");
    printPlayer1PunchPlayer2Block1();
    usleep(150000);
    system("clear");
    printPlayer1PunchPlayer2Block2();
    usleep(150000);
    system("clear");
    printPlayer1PunchPlayer2Block3();
    usleep(150000);
    system("clear");
    printPlayer1PunchPlayer2Block0();
    usleep(1000000);
    system("clear");
}

void printPlayer1BlockPlayer2Punch0(){
    ifstream fighter3;
    fighter3.open("Images/player1BlockPlayer2Punch/player1BlockPlayer2Punch0.txt");
    if(!fighter3.is_open()){
        cout << "Fighter 0 is not open" << endl;
    }
    string str;
    while(getline(fighter3, str)){
        cout << str << endl;
    }
    fighter3.close();
}

void printPlayer1BlockPlayer2Punch1(){
    ifstream fighter3;
    fighter3.open("Images/player1BlockPlayer2Punch/player1BlockPlayer2Punch1.txt");
    if(!fighter3.is_open()){
        cout << "Fighter 1 is not open" << endl;
    }
    string str;
    while(getline(fighter3, str)){
        cout << str << endl;
    }
    fighter3.close();
}

void printPlayer1BlockPlayer2Punch2(){
    ifstream fighter3;
    fighter3.open("Images/player1BlockPlayer2Punch/player1BlockPlayer2Punch2.txt");
    if(!fighter3.is_open()){
        cout << "Fighter 2 is not open" << endl;
    }
    string str;
    while(getline(fighter3, str)){
        cout << str << endl;
    }
    fighter3.close();
}

void printPlayer1BlockPlayer2Punch3(){
    ifstream fighter3;
    fighter3.open("Images/player1BlockPlayer2Punch/player1BlockPlayer2Punch3.txt");
    if(!fighter3.is_open()){
        cout << "Fighter 3 is not open" << endl;
    }
    string str;
    while(getline(fighter3, str)){
        cout << str << endl;
    }
    fighter3.close();
}

void player1BlockPlayer2Punch(){
    system("clear");
    printPlayer1BlockPlayer2Punch0();
    usleep(1000000);
    system("clear");
    printPlayer1BlockPlayer2Punch1();
    usleep(150000);
    system("clear");
    printPlayer1BlockPlayer2Punch2();
    usleep(150000);
    system("clear");
    printPlayer1BlockPlayer2Punch3();
    usleep(150000);
    system("clear");
    printPlayer1BlockPlayer2Punch0();
    usleep(1000000);
    system("clear");
}

void printPlayer1BlockPlayer2Block0(){
    ifstream fighter3;
    fighter3.open("Images/player1BlockPlayer2Block/player1BlockPlayer2Block0.txt");
    if(!fighter3.is_open()){
        cout << "Fighter 0 is not open" << endl;
    }
    string str;
    while(getline(fighter3, str)){
        cout << str << endl;
    }
    fighter3.close();
}

void printPlayer1BlockPlayer2Block1(){
    ifstream fighter3;
    fighter3.open("Images/player1BlockPlayer2Block/player1BlockPlayer2Block1.txt");
    if(!fighter3.is_open()){
        cout << "Fighter 1 is not open" << endl;
    }
    string str;
    while(getline(fighter3, str)){
        cout << str << endl;
    }
    fighter3.close();
}

void player1BlockPlayer2Block(){
    system("clear");
    printPlayer1BlockPlayer2Block0();
    usleep(1000000);
    system("clear");
    printPlayer1BlockPlayer2Block1();
    usleep(1000000);
    system("clear");
    printPlayer1BlockPlayer2Block0();
    usleep(150000);
    system("clear"); 
}

void player1PunchPlayer2Punch(){
    system("clear");
    printPlayer1PunchPlayer2Block0();
    usleep(1000000);
    system("clear");
    printPlayer1PunchPlayer2Block1();
    usleep(150000);
    system("clear");
    printPlayer1PunchPlayer2Block2();
    usleep(150000);
    system("clear");
    printPlayer1PunchPlayer2Block3();
    usleep(150000);
    system("clear");
    printPlayer1PunchPlayer2Block0();
    usleep(300000);
    system("clear");
    printPlayer1BlockPlayer2Punch0();
    usleep(300000);
    system("clear");
    printPlayer1BlockPlayer2Punch1();
    usleep(150000);
    system("clear");
    printPlayer1BlockPlayer2Punch2();
    usleep(150000);
    system("clear");
    printPlayer1BlockPlayer2Punch3();
    usleep(150000);
    system("clear");
    printPlayer1BlockPlayer2Punch0();
    usleep(1000000);
    system("clear");
}

int getChoice(){
    int choice;
    cout << "Enter 1 to punch" << endl;
    cout << "Enter 2 to block" << endl;
    cout << "Enter -1 to quit" << endl;
    cin >> choice;
    if((choice >= 1) && (choice <= 2)){
        return choice;
    } else if (choice == -1){
        return choice;
    } else {
        cout << "Invalid input. Enter a different option." << endl;
        int newChoice = getChoice();
        return newChoice;
    }
    return -1;
}

int playEncounter(){
    system("clear");
    printPlayer1PunchPlayer2Block0();
    cout << "Player 1, what would you like to do?" << endl;
    int player1Choice = getChoice();
    cout << "Player 2, what would you like to do?" << endl;
    int player2Choice = getChoice();
    if((player1Choice != -1) && (player2Choice != -1)){
        if((player1Choice == 1) && (player2Choice == 2)){
            player1PunchPlayer2Block();
            playEncounter();
        } else if((player2Choice == 1) && (player1Choice == 2)){
            player1BlockPlayer2Punch();
            playEncounter();
        } else if((player1Choice == 2) && (player2Choice == 2)){
            player1BlockPlayer2Block();
            playEncounter();
        } else if((player1Choice == 1) && (player2Choice == 1)){
            player1PunchPlayer2Punch();
            playEncounter();
        }
    }
    system("clear");
    return 0;
}

int main(){
    playEncounter();
    return 0;
}
