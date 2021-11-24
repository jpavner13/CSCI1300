/* Main Function
    1. Print menu with options to play or sign up
    2. Ask players for name and password
    3. Bring up new menu to play, buy/sell fighters
    4. If playing, print fighters/ground
    5. Ask for input from both players
    6. evaluate winner
    7. calc and update hp
    8. Once player runs out of hp, display winner
    9. Increment fight for boht players
    10. Pay players earnings
    11. Repeat until players quit
*/
#include "Player.h"
#include "Fighter.h"
//#include "Ground.h"
#include "Menu.h"
#include <fstream>
#include <unistd.h>
#include <string>
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
    system("clear");
    cout << "SHOP"<< endl;
    cout << "1: Buy Fighters" << endl << "2: Sell Players" << endl << "3: Back" << endl;
    int option;
    cin >> option;
    ifstream file;
    file.open("Players.txt");
    string playerLine;
    string playerArr[74];
    Fighter playerFighters[10];
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
        cout << finalStr;
        ofstream outFile;
        outFile.open("Players.txt");
        outFile << finalStr;
        outFile.close();
    } else if(option == 2){
        system("clear");
        cout << "Enter username:" << endl;
        string enteredName;
        cin >> enteredName;
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
                cout << "Enter password:" << endl;
                string password;
                cin >> password;
                if(password == playerArr[1]){
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
                        int sellOption;
                        for(int i = 0; i < counter; i++){
                            cout << (i + 1) << ": " << playerFighters[i].getFighterName() << "\t\t\t$" << playerFighters[i].getPrice() << endl;
                        }
                        cin >> sellOption;
                        string confirm;
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
            ofstream editFile;
            editFile.open("Players.txt");
            editFile << newFileString;
            editFile.close();
        }
        if(!nameExists){
            cout << "Username does not exist" << endl;
            usleep(5000000);
            runShop(menu);
        }





    } else if(option == 3){
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
            createAccount(menu);
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

int main(){
    Menu menu1 = Menu();
    menu1.setGameName("Boxing");
    menu1.setMenuOptionNameAt(0, "Play Game");
    menu1.setMenuOptionNameAt(1, "Shop");
    menu1.setMenuOptionNameAt(2, "Create New Player");
    menu1.setMenuOptionNameAt(3, "Quit");

    bool playingGame = true;

    while(playingGame){
        menu1.printMenu();
        int choice = menu1.getChoice();
        if(choice == 1){

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