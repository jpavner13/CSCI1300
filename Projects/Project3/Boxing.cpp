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
    if(option == 1){
        system("clear");
        cout << "Enter username:" << endl;
        string name;
        string str;
        cin >> name;
        bool nameExists = false;
        Fighter playerFighters[10];
        while(getline(file, str)){
            string arr[74];
            split(str, ',', arr, 74);
            if(name == arr[0]){
                nameExists = true;
                string password;
                cout << "Enter password:" << endl;
                cin >> password;
                if(password == arr[1]){
                    cout << "Logged in" << endl;
                    Player player(arr[0], arr[1], stoi(arr[2]), stoi(arr[3]));
                    cout << player.getPlayerName() << "'s balance: $" << player.getPlayerAccountBalance() << endl;
                    int counter = 0;
                    for(int i = 4; i < ((player.getNumberOfFighters() * 7) + 4); i += 7){
                        Fighter currentFighter(arr[i], stoi(arr[i + 1]), stoi(arr[i + 2]), stoi(arr[i + 3]), stoi(arr[i + 4]), stoi(arr[i + 5]), stoi(arr[i + 6]));
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
                        string arr[10];
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
                                    player.setPlayerAccountBalance(player.getPlayerAccountBalance() - fighters[fighterChoice - 1].getPrice());
                                    playerFighters[player.getNumberOfFighters()] = fighters[fighterChoice - 1];
                                    player.incrementNumOfFighters();
                                    cout << playerFighters[player.getNumberOfFighters() - 1].getFighterName() << endl;
                                    
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

                        usleep(5000000);
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
            }
        }
        if(!nameExists){
            cout << "Username does not exist" << endl;
            usleep(5000000);
            runShop(menu);
        }
    } else if(option == 2){
        system("clear");

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
        if(arr[0] == name){
            menu.userExists();
            usleep(5000000);
            createAccount(menu);
        }
        fullFile = fullFile + (str + "\n");
    }
    menu.askPassword();
    cin >> password;
    char input;
    while(input != 'y'){
        system("clear");
        menu.welcome();
        cin >> input;
    }

    fullFile +=  (name + "," + password + "," + "10000" + "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0");
    ofstream printFile;
    printFile.open("Players.txt");
    printFile << fullFile << endl;

    input = ' ';
    file.close();
    printFile.close();
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