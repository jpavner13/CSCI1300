#include "Player.h"
#include "Fighter.h"
#include "Ring.h"
#include "Menu.h"
#include <fstream>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int split(string str, char sep, string arr[], int arrSize){
    string current = "";
    int count = 1;
    if(str.length() < 1){
        count = 0;
    }
    int arrCurrent = 0;
    int length = str.length();
    for(int i = 0; i < length; i++){
        if(str[i] == sep){
            arr[arrCurrent] = current;
            current = "";
            arrCurrent++;
            count++;
        } else {
            current += str[i];
        }
    }
    if(arrSize < count){
        count = -1;
    }
    arr[arrCurrent] = current;
    return count;
}

void runShop(Menu menu){
    ifstream safety;
    safety.open("Players.txt");
    string str;
    string safetyString;
    while(getline(safety, str)){
        safetyString += str;
        safetyString += "\n";
    }
    safety.close();
    system("clear");
    menu.printShopTitle();
    int option;
    cin >> option;
    ifstream file;
    file.open("Players.txt");
    string playerLine;
    string playerArr[74];
    Fighter playerFighters[10];
    int sellOption;
    if(option == 1){
        system("clear");
        cout << "Enter username:" << endl;
        string name;
        string str;
        cin >> name;
        bool nameExists = false;
        string finalStr = "";
        while(getline(file, str)){
            split(str, ',', playerArr, 74);
            if(name == playerArr[0]){
                nameExists = true;
                playerLine = str;
                string password;
                cout << "Enter password:" << endl;
                cin >> password;
                if(password == playerArr[1]){
                    system("clear");
                    cout << "Logged in" << endl;
                    Player player(playerArr[0], playerArr[1], stoi(playerArr[2]), stoi(playerArr[3]));
                    cout << player.getPlayerName() << "'s balance: $" << player.getPlayerAccountBalance() << endl;
                    int counter = 0;
                    for(int i = 4; i < ((player.getNumberOfFighters() * 7) + 4); i += 7){
                        Fighter currentFighter(playerArr[i], stoi(playerArr[i + 1]), stoi(playerArr[i + 2]), stoi(playerArr[i + 3]), stoi(playerArr[i + 4]), stoi(playerArr[i + 5]), stoi(playerArr[i + 6]));
                        playerFighters[counter] = currentFighter;
                        counter++;
                    }
                    menu.printFighterShop();
                    string buyChoice;
                    cin >> buyChoice;
                    if(buyChoice == "q"){
                        runShop(menu);
                    } else if((buyChoice == "1") || (buyChoice == "2") || (buyChoice == "3") || (buyChoice == "4") || (buyChoice == "5") || (buyChoice == "6") || (buyChoice == "7") || (buyChoice == "8") || (buyChoice == "9") || (buyChoice == "10")){
                        ifstream fighterFile;
                        fighterFile.open("Fighters.txt");
                        Fighter fighters[10];
                        string str;
                        string arr[7];
                        int counter = 0;
                        while(getline(fighterFile, str)){
                            split(str, ',', arr, 7);
                            Fighter currentFighter(arr[0], stoi(arr[1]), stoi(arr[2]), stoi(arr[3]), stoi(arr[4]), stoi(arr[5]), stoi(arr[6]));
                            fighters[counter] = currentFighter;
                            counter++;
                        }
                        int fighterChoice = stoi(buyChoice);
                        cout << "Fighter selected: " <<  fighters[fighterChoice - 1].getFighterName() << endl;
                        cout << "Would you like to purchace this fighter? (y/n)" << endl;
                        string verify;
                        cin >> verify;
                        if(verify == "y" || verify == "n"){
                            if(verify == "y"){
                                if(player.getPlayerAccountBalance() >= fighters[fighterChoice - 1].getPrice()){
                                    cout << "Purchasing fighter..." << endl;
                                    player.incrementNumOfFighters();
                                    usleep(1000000);
                                    player.setPlayerAccountBalance(player.getPlayerAccountBalance() - fighters[fighterChoice - 1].getPrice());
                                    playerFighters[player.getNumberOfFighters()] = fighters[fighterChoice - 1];
                                    cout << playerFighters[player.getNumberOfFighters()].getFighterName() << endl;
                                    int i = (((player.getNumberOfFighters() - 1) * 7) + 4);
                                    playerArr[2] = to_string(stoi(playerArr[2]) - fighters[fighterChoice - 1].getPrice());
                                    playerArr[3] = to_string(stoi(playerArr[3]) + 1);
                                    playerArr[i] = fighters[fighterChoice - 1].getFighterName();
                                    playerArr[i+ 1] = to_string(fighters[fighterChoice - 1].getHp());
                                    playerArr[i+ 2] = to_string(fighters[fighterChoice - 1].getPower());
                                    playerArr[i+ 3] = to_string(fighters[fighterChoice - 1].getLevel());
                                    playerArr[i+ 6] = to_string(fighters[fighterChoice - 1].getPrice());
                                    string addStr = "";
                                    for(int i = 0; i < 73; i++){
                                        if(i == 72){
                                            addStr += playerArr[i];
                                        } else {
                                            addStr += playerArr[i];
                                            addStr += ",";
                                        }
                                    }
                                    addStr += "\n";
                                    finalStr += addStr;
                                    usleep(5000000);
                                    cout << "Fighter Purchaced!" << endl;
                                    usleep(5000000);
                                } else {
                                    cout << "Insufficient funds." << endl;
                                    usleep(5000000);
                                    runShop(menu);
                                }
                            } else {
                                cout << "Canceling" << endl;
                                usleep(3000000);
                                runShop(menu);
                            }
                        } else {
                            cout << "Invalad input" << endl;
                            runShop(menu);
                        }
                    } else {
                        cout << "Invalid input." << endl;
                        usleep(5000000);
                        runShop(menu);
                    }
                } else {
                    cout << "Incorrect password. Try logging in again." << endl;
                    usleep(5000000);
                    runShop(menu);
                }
            } else {
                finalStr += str;
                finalStr += "\n";
            }
        }
        if(!nameExists){
            cout << "Username does not exist" << endl;
            usleep(5000000);
            runShop(menu);
        }
        //cout << finalStr;
        ofstream outFile;
        outFile.open("Players.txt");
        outFile << finalStr;
        outFile.close();
    } else if(option == 2){
        system("clear");
        cout << "Enter username:" << endl;
        string enteredName;
        cin >> enteredName;
        cout << "Enter password:" << endl;
        string password;
        cin >> password;
        ifstream file;
        file.open("Players.txt");
        if(file.is_open()){
        } else {
            cout << "File could not open" << endl;
        }
        string str;
        bool nameExists = false;
        string newFileString;
        while(getline(file, str)){
            //cout << "Trying to split" << endl;
            split(str, ',', playerArr, 74);
            //cout << "Split" << endl;
            if(playerArr[0] == enteredName){
                nameExists = true;
                if(password == playerArr[1]){
                    system("clear");
                    cout << "Logged in" << endl;
                    Player player(playerArr[0], playerArr[1], stoi(playerArr[2]), stoi(playerArr[3]));
                    cout << player.getPlayerName() << "'s balance: $" << player.getPlayerAccountBalance() << endl;
                    int counter = 0;
                    for(int i = 4; i < ((player.getNumberOfFighters() * 7) + 4); i += 7){
                        Fighter currentFighter(playerArr[i], stoi(playerArr[i + 1]), stoi(playerArr[i + 2]), stoi(playerArr[i + 3]), stoi(playerArr[i + 4]), stoi(playerArr[i + 5]), stoi(playerArr[i + 6]));
                        playerFighters[counter] = currentFighter;
                        counter++;
                    }
                    if(player.getNumberOfFighters() <= 0){
                        cout << "No fighters to sell." << endl;
                        newFileString += str;
                        newFileString += "\n";
                    } else {
                        cout << "Which fighter would you like to sell?" << endl;
                        for(int i = 0; i < counter; i++){
                            cout << (i + 1) << ": " << playerFighters[i].getFighterName() << "\t\t\t$" << playerFighters[i].getPrice() << endl;
                        }
                        cout << "Enter 11 to quit" << endl;
                        cin >> sellOption;
                        string confirm;
                        if(sellOption == 11){
                            ofstream editFile;
                            editFile.open("Players.txt");
                            editFile << safetyString;
                            editFile.close();
                            runShop(menu);
                        } else {
                            cout << "You wish to sell " << playerFighters[sellOption - 1].getFighterName() << ". Is this correct? (y/n)" << endl;
                            cin >> confirm;
                            if(confirm == "y"){
                                cout << "Selling " << playerFighters[sellOption - 1].getFighterName() << "." << endl;
                                bool foundInArr = false;
                                int index;
                                for(int i = 0; i < 10; i++){
                                    if(i == (sellOption -1)){
                                        index = i;
                                        foundInArr = true;
                                        player.decrementNumberOfFighters();
                                        //cout << (playerFighters[sellOption - 1].getPrice()) << endl;
                                        player.setPlayerAccountBalance(player.getPlayerAccountBalance() + playerFighters[sellOption - 1].getPrice());
                                        playerFighters[i] = playerFighters[i + 1];
                                    } else {
                                        if(foundInArr){
                                            playerFighters[i] = playerFighters[i + 1];
                                        }
                                    }
                                }
                                //player.setPlayerAccountBalance(player.getPlayerAccountBalance() - playerFighters[sellOption - 2].getPrice());
                                //player.incrementNumOfFighters();
                                for(int i = 0; i < 4; i++){
                                    if(i == 2){
                                        newFileString += to_string(player.getPlayerAccountBalance());
                                        //cout << player.getPlayerAccountBalance() << endl;
                                        newFileString += ",";
                                    } else if (i == 3){
                                        newFileString += to_string(player.getNumberOfFighters());
                                        newFileString += ","; 
                                    } else {
                                        newFileString += playerArr[i];
                                        newFileString += ",";
                                    }
                                }
                                string fighterString;
                                string fighterStringArr[70];
                                for(int i = 0; i < player.getNumberOfFighters(); i++){
                                    fighterString += playerFighters[i].getFighterName();
                                    fighterStringArr[i * 7] = playerFighters[i].getFighterName();
                                    fighterString += ",";
                                    fighterString += to_string(playerFighters[i].getHp());
                                    fighterStringArr[(i * 7) + 1] = to_string(playerFighters[i].getHp());
                                    fighterString += ",";
                                    fighterString += to_string(playerFighters[i].getPower());
                                    fighterStringArr[(i * 7) + 2] = to_string(playerFighters[i].getPower());
                                    fighterString += ",";
                                    fighterString += to_string(playerFighters[i].getLevel());
                                    fighterStringArr[(i * 7) + 3] = to_string(playerFighters[i].getLevel());
                                    fighterString += ",";
                                    fighterString += to_string(playerFighters[i].getFightsWon());
                                    fighterStringArr[(i * 7) + 4] = to_string(playerFighters[i].getFightsWon());
                                    fighterString += ",";
                                    fighterString += to_string(playerFighters[i].getTotalFights());
                                    fighterStringArr[(i * 7) + 5] = to_string(playerFighters[i].getTotalFights());
                                    fighterString += ",";
                                    fighterString += to_string(playerFighters[i].getPrice());
                                    fighterStringArr[(i * 7) + 6] = to_string(playerFighters[i].getPrice());
                                    fighterString += ",";
                                }
                                newFileString += fighterString;
                                for(int i = player.getNumberOfFighters() * 7; i < 70; i++){
                                    if(i == 69){
                                        newFileString += "0";
                                    } else{
                                        newFileString += "0,";
                                    }
                                }
                                newFileString += "\n";
                            } else {
                                cout << "Canceling" << endl;
                                usleep(5000000);
                                
                                runShop(menu);
                            }
                        }
                    }
                    usleep(5000000);
                } else {
                    cout << "Password Incorrect" << endl;
                    usleep(5000000);
                    runShop(menu);
                }
            } else {
                for(int i = 0; i < 74; i++){
                    if(i == 73){
                        newFileString += playerArr[i];
                    } else {
                        newFileString += playerArr[i];
                        newFileString += ",";
                    }
                }
                newFileString += "\n";
            }
            if(sellOption != 11){
                ofstream editFile;
                editFile.open("Players.txt");
                editFile << newFileString;
                editFile.close();
            }
        }
        if(!nameExists){
            cout << "Username does not exist" << endl;
            usleep(5000000);
            runShop(menu);
        }
    } else if(option == 3){
        system("clear");
        cout << "Enter Username:" << endl;
        string username;
        cin >> username;
        ifstream file;
        file.open("Players.txt");
        string str;
        string arr[74];
        string outString;
        while(getline(file, str)){
            split(str, ',', arr, 74);
            if(arr[0] == username){
                cout << "Enter Password:" << endl;
                string password;
                cin >> password;
                if(arr[1] == password){
                    system("clear");
                    cout << "Which fighter would you like to upgrade?" << endl;
                    int counter = 1;
                    for(int i = 4; i < stoi(arr[3]) * 7; i += 7){
                        cout << counter << ": " << arr[i] << endl;
                        counter++;
                    }
                    int choice;
                    cin >> choice;
                    cout << "You would like to upgrade: " << arr[((choice - 1) * 7) + 4] << "? (y/n)" << endl;
                    string confirm;
                    cin >> confirm;
                    if(confirm == "y"){
                        arr[2] = to_string(stoi(arr[2]) - 3000);
                        arr[((choice - 1) * 7) + 5] = to_string(stoi(arr[((choice - 1) * 7) + 5]) + 50);
                        arr[((choice - 1) * 7) + 6] = to_string(stoi(arr[((choice - 1) * 7) + 6]) + 10);
                        arr[((choice - 1) * 7) + 7] = to_string(stoi(arr[((choice - 1) * 7) + 7]) + 1);
                        arr[((choice - 1) * 7) + 10] = to_string(stoi(arr[((choice - 1) * 7) + 10]) + 3000);
                        string addString;
                        for(int i = 0; i < 74; i++){
                            if(i == 73){
                                addString += arr[i];
                            } else {
                                addString += arr[i];
                                addString += ",";
                            }
                        }
                        addString += "\n";
                        outString += addString;
                    } else {
                        runShop(menu);
                    }
                } 
            } else {
                outString += str;
                outString += "\n";
            }
        }
        ofstream outFile;
        outFile.open("Players.txt");
        outFile << outString;
        outFile.close();
        file.close();
    } else if(option == 4){
        file.close();
        return;
    }
    file.close();
}

void createAccount(Menu menu){
    system("clear");
    ifstream file;
    file.open("Players.txt");
    if(!file.is_open()){
        cout << "Could not open file" << endl;
        return;
    }
    string str;
    string name;
    string password;
    menu.askName();
    cin >> name;
    string arr[74];
    string fullFile = "";
    while(getline(file, str)){
        split(str, ',', arr, 74);
        //cout << "Split successful" << endl;
        if(arr[0] == name){
            menu.userExists();
            usleep(5000000);
            return;
        }
        //cout << "Broke in loop" << endl;
        fullFile = fullFile + (str + "\n");
    }
    menu.askPassword();
    cin >> password;
    system("clear");
    menu.welcome();
    string input;
    cin >> input;

    if(input == "y"){
        fullFile +=  (name + "," + password + "," + "10000,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0");
        ofstream printFile;
        printFile.open("Players.txt");
        printFile << fullFile << endl;

        input = "n";
        file.close();
        printFile.close();
    } else {
        cout << "Account not confirmed, try again." << endl;
        createAccount(menu);
    }
}

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

int playEncounter(Fighter fighter1, Fighter fighter2, Player player1, Player player2){
    system("clear");
    cout << fighter1.getFighterName() << ":\t HP: " << fighter1.getHp() << "\t\t\t\t\t\t\t\t\t\t" << fighter2.getFighterName() <<  ": \tHP: " << fighter2.getHp() << endl;
    cout << "\t\t" << "Power: " << fighter1.getPower() << "\t\t\t\t\t\t\t\t\t" << "\t\t" <<  "Power: " << fighter2.getPower() << endl;
    cout << endl;
    printPlayer1PunchPlayer2Block0();
    cout << "Player 1, what would you like to do?" << endl;
    int player1Choice = getChoice();
    system("clear");
    cout << fighter1.getFighterName() << ":\t HP: " << fighter1.getHp() << "\t\t\t\t\t\t\t\t\t\t" << fighter2.getFighterName() <<  ": \tHP: " << fighter2.getHp() << endl;
    cout << "\t\t" << "Power: " << fighter1.getPower() << "\t\t\t\t\t\t\t\t\t" << "\t\t" <<  "Power: " << fighter2.getPower() << endl;
    cout << endl;
    printPlayer1PunchPlayer2Block0();
    cout << "Player 2, what would you like to do?" << endl;
    int player2Choice = getChoice();
    if((player1Choice != -1) && (player2Choice != -1)){
        if((player1Choice == 1) && (player2Choice == 2)){
            player1PunchPlayer2Block();
            fighter2.setHp(fighter2.getHp() - (fighter1.getPower() / 2));
            if(fighter2.getHp() > 0){
                playEncounter(fighter1, fighter2, player1, player2);
            } else {
                cout << "Player 1 Wins!" << endl;
                fighter1.incrementFightsWon();
                fighter1.incrementTotalFights();
                fighter2.incrementTotalFights();
                ifstream file;
                    file.open("Players.txt");
                    string str;
                    string arr[74];
                    string outString;
                    while(getline(file, str)){
                        split(str, ',', arr, 74);
                        if(arr[0] == player1.getPlayerName()){
                            arr[2] = to_string(stoi(arr[2]) + 5000);
                            for(int i = 4; i < 70; i += 7){
                                if(arr[i] == fighter1.getFighterName()){
                                    arr[i + 4] = to_string(stoi(arr[i + 4]) + 1);
                                    arr[i + 5] = to_string(stoi(arr[i + 5]) + 1);
                                }
                            }
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        } else if(arr[0] == player2.getPlayerName()){
                            for(int i = 4; i < 70; i += 7){
                                if(arr[i] == fighter2.getFighterName()){
                                    arr[i + 5] = to_string(stoi(arr[i + 5]) + 1);
                                }
                            }
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        } else {
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        }
                    }
                    ofstream outFile;
                    outFile.open("Players.txt");
                    outFile << outString;
            }
        } else if((player2Choice == 1) && (player1Choice == 2)){
            player1BlockPlayer2Punch();
            fighter1.setHp(fighter1.getHp() - (fighter2.getPower() / 2));
            if(fighter1.getHp() > 0){
                playEncounter(fighter1, fighter2, player1, player2);
            } else {
                cout << "Player 2 Wins!" << endl;
                fighter2.incrementFightsWon();
                fighter2.incrementTotalFights();
                fighter1.incrementTotalFights();
                ifstream file;
                    file.open("Players.txt");
                    string str;
                    string arr[74];
                    string outString;
                    while(getline(file, str)){
                        split(str, ',', arr, 74);
                        if(arr[0] == player2.getPlayerName()){
                            arr[2] = to_string(stoi(arr[2]) + 5000);
                            for(int i = 4; i < 70; i += 7){
                                if(arr[i] == fighter2.getFighterName()){
                                    arr[i + 4] = to_string(stoi(arr[i + 4]) + 1);
                                    arr[i + 5] = to_string(stoi(arr[i + 5]) + 1);
                                }
                            }
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        } else if(arr[0] == player1.getPlayerName()){
                            for(int i = 4; i < 70; i += 7){
                                if(arr[i] == fighter1.getFighterName()){
                                    arr[i + 5] = to_string(stoi(arr[i + 5]) + 1);
                                }
                            }
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        } else {
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        }
                    }
                    ofstream outFile;
                    outFile.open("Players.txt");
                    outFile << outString;
            }
        } else if((player1Choice == 2) && (player2Choice == 2)){
            player1BlockPlayer2Block();
            playEncounter(fighter1, fighter2, player1, player2);
        } else if((player1Choice == 1) && (player2Choice == 1)){
            player1PunchPlayer2Punch();
            fighter1.setHp(fighter1.getHp() - fighter2.getPower());
            fighter2.setHp(fighter2.getHp() - fighter1.getPower());
            if(fighter1.getHp() > 0){
                if(fighter2.getHp() > 0){
                    playEncounter(fighter1, fighter2, player1, player2);
                } else {
                    cout << "Player 1 Wins!" << endl;
                    fighter1.incrementFightsWon();
                    fighter1.incrementTotalFights();
                    fighter2.incrementTotalFights();
                    ifstream file;
                    file.open("Players.txt");
                    string str;
                    string arr[74];
                    string outString;
                    while(getline(file, str)){
                        split(str, ',', arr, 74);
                        if(arr[0] == player1.getPlayerName()){
                            arr[2] = to_string(stoi(arr[2]) + 5000);
                            for(int i = 4; i < 70; i += 7){
                                if(arr[i] == fighter1.getFighterName()){
                                    arr[i + 4] = to_string(stoi(arr[i + 4]) + 1);
                                    arr[i + 5] = to_string(stoi(arr[i + 5]) + 1);
                                }
                            }
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        } else if(arr[0] == player2.getPlayerName()){
                            for(int i = 4; i < 70; i += 7){
                                if(arr[i] == fighter2.getFighterName()){
                                    arr[i + 5] = to_string(stoi(arr[i + 5]) + 1);
                                }
                            }
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        } else {
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        }
                    }
                    ofstream outFile;
                    outFile.open("Players.txt");
                    outFile << outString;
                }
            } else {
                cout << "Player 2 Wins!" << endl;
                fighter2.incrementFightsWon();
                fighter2.incrementTotalFights();
                fighter1.incrementTotalFights();
                ifstream file;
                    file.open("Players.txt");
                    string str;
                    string arr[74];
                    string outString;
                    while(getline(file, str)){
                        split(str, ',', arr, 74);
                        if(arr[0] == player2.getPlayerName()){
                            arr[2] = to_string(stoi(arr[2]) + 5000);
                            for(int i = 4; i < 70; i += 7){
                                if(arr[i] == fighter2.getFighterName()){
                                    arr[i + 4] = to_string(stoi(arr[i + 4]) + 1);
                                    arr[i + 5] = to_string(stoi(arr[i + 5]) + 1);
                                }
                            }
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        } else if(arr[0] == player1.getPlayerName()){
                            for(int i = 4; i < 70; i += 7){
                                if(arr[i] == fighter1.getFighterName()){
                                    arr[i + 5] = to_string(stoi(arr[i + 5]) + 1);
                                }
                            }
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        } else {
                            for(int i = 0; i < 74; i++){
                                if(i == 73){
                                    outString += arr[i];
                                } else {
                                    outString += arr[i];
                                    outString += ",";
                                }
                            }
                            outString += "\n";
                        }
                    }
                    ofstream outFile;
                    outFile.open("Players.txt");
                    outFile << outString;
            }
        }
    }
    return 0;
}

void playGame(){
    system("clear");
    string player1Username;
    string player2Username;
    cout << "Player 1, enter username:" << endl;
    cin >> player1Username;
    ifstream file;
    string str;
    file.open("Players.txt");
    string playerArr[74];
    Player player1;
    Player player2;
    while(getline(file, str)){
        split(str, ',', playerArr, 74);
        if(playerArr[0] == player1Username){
            string player1Password;
            cout << "Enter password" << endl;
            cin >> player1Password;
            if(playerArr[1] == player1Password){
                Player playerOne(playerArr[0], playerArr[1], stoi(playerArr[2]), stoi(playerArr[3]));
                player1 = playerOne;
                int counter = 0;
                int numOfFighters = player1.getNumberOfFighters();
                for(int i = 4; i < ((numOfFighters * 7) + 4); i += 7){
                    Fighter currentFighter(playerArr[i], stoi(playerArr[i + 1]), stoi(playerArr[i + 2]), stoi(playerArr[i + 3]), stoi(playerArr[i + 4]), stoi(playerArr[i + 5]), stoi(playerArr[i + 6]));
                    player1.addPLayerFighterAt(currentFighter, counter);
                    counter++;
                }
            }
        }
    }
    file.close();
    system("clear");
    cout << "Player 2, enter username:" << endl;
    cin >> player2Username;
    ifstream infile;
    infile.open("Players.txt");
    while(getline(infile, str)){
        split(str, ',', playerArr, 74);
        if(playerArr[0] == player2Username){
            string player2Password;
            cout << "Enter password" << endl;
            cin >> player2Password;
            if(playerArr[1] == player2Password){
                Player playerTwo(playerArr[0], playerArr[1], stoi(playerArr[2]), stoi(playerArr[3]));
                player2 = playerTwo;
                int counter = 0;
                int numOfFighters = player2.getNumberOfFighters();
                for(int i = 4; i < ((numOfFighters * 7) + 4); i += 7){
                    Fighter currentFighter(playerArr[i], stoi(playerArr[i + 1]), stoi(playerArr[i + 2]), stoi(playerArr[i + 3]), stoi(playerArr[i + 4]), stoi(playerArr[i + 5]), stoi(playerArr[i + 6]));
                    player2.addPLayerFighterAt(currentFighter, counter);
                    counter++;
                }
            }
        }
    }
    system("clear");
    cout << player1.getPlayerName() <<", which player would you like to use?" << endl;
    Fighter fighter1;
    for(int i = 0; i < player1.getNumberOfFighters(); i++){
        cout << i + 1 << ": " << player1.getPlayerFighterAt(i).getFighterName() << endl;
    }
    int choice;
    cin >> choice;
    fighter1 = player1.getPlayerFighterAt(choice - 1);
    system("clear");
    cout << player2.getPlayerName() << ", which player would you like to use?" << endl;
    Fighter fighter2;
    for(int i = 0; i < player2.getNumberOfFighters(); i++){
        cout << i + 1 << ": " << player2.getPlayerFighterAt(i).getFighterName() << endl;
    }
    cin >> choice;
    fighter2 = player2.getPlayerFighterAt(choice - 1);

    system("clear");
    cout << fighter1.getFighterName() << " VS. " << fighter2.getFighterName() << endl;
    usleep(3000000);
    system("clear");
    Ring ring;
    char move;
    bool playerCollide = false;
    while(!playerCollide){
        int player1MoveNum = rand() % 10;
        for(int i = 0; i < player1MoveNum; i++){
            if((rand() % 10) == 0){
                int x = rand() % 15;
                int y = rand() % 15;
                ring.setPowerUpPos(x, y);
            } 
            if(!playerCollide){
                system("clear");
                cout << player1.getPlayerName() << ", has " << player1MoveNum - i << " moves left" << endl;
                ring.displayRing();
                if(ring.powerUpCollide1()){
                    string power;
                    if((rand() % 2) == 0){
                        power = "Health";
                        fighter1.setHp(fighter1.getHp() + 100);
                        cout << "Player 1 got: " << power << " + 100" << endl;
                    } else {
                        power = "Power";
                        fighter1.setPower(fighter1.getPower() + 10);
                        cout << "Player 1 got: " << power << " + 10" << endl;
                    }
                }
                ring.displayMoves(1);
                cin >> move;
                ring.makeMove(1,move);
                if(ring.playersCollide()){
                    playerCollide = true;
                }
            }
        }
        int player2MoveNum = rand() % 10;
        for(int i = 0; i < player2MoveNum; i++){
            if((rand() % 10) == 0){
                int x = rand() % 15;
                int y = rand() % 15;
                ring.setPowerUpPos(x, y);
            } 
            if(!playerCollide){
                system("clear");
                cout << player2.getPlayerName() << ", has " << player2MoveNum - i << " moves left" << endl;
                ring.displayRing();
                if(ring.powerUpCollide2()){
                    string power;
                    if((rand() % 2) == 0){
                        power = "Health";
                        fighter2.setHp(fighter2.getHp() + 100);
                        cout << "Player 2 got: " << power << " + 100" << endl;
                    } else {
                        power = "Power";
                        fighter2.setPower(fighter2.getPower() + 10);
                        cout << "Player 2 got: " << power << " + 10" << endl;
                    }
                }
                ring.displayMoves(2);
                cin >> move;
                ring.makeMove(2,move);
                if(ring.playersCollide()){
                    playerCollide = true;
                }
            }
        }
    }
    cout << "Players Collided" << endl;
    usleep(2000000);
    playEncounter(fighter1, fighter2, player1, player2);
    usleep(10000000);
}

int main(){
    Menu menu1 = Menu();
    menu1.setGameName("Boxing");
    menu1.setMenuOptionNameAt(0, "Play Game");
    menu1.setMenuOptionNameAt(1, "Shop");
    menu1.setMenuOptionNameAt(2, "Create New Player");
    menu1.setMenuOptionNameAt(3, "Quit");

    srand(time(0));

    bool playingGame = true;

    while(playingGame){
        menu1.printMenu();
        int choice = menu1.getChoice();
        if(choice == 1){
            playGame();
        } else if(choice == 2){
            runShop(menu1);
        } else if(choice == 3){
            createAccount(menu1);
        } else if(choice == 4){
            system("clear");
            playingGame = false;
        }
    }
}