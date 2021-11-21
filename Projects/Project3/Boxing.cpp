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
//#include "Player.h"
//#include "Fighter.h"
//#include "Ground.h"
#include "Menu.h"
#include <ifstream>

int main(){
    Menu menu1 = Menu();
    menu1.setGameName("Boxing");
    menu1.setMenuOptionNameAt(0, "Play Game");
    menu1.setMenuOptionNameAt(1, "Shop");
    menu1.setMenuOptionNameAt(2, "Create New Player");

    bool playingGame = true;

    while(playingGame){
        menu1.printMenu();
        int choice = menu1.getChoice();
        cout << choice << endl;
        if(choice == 1){

        } else if(choice == 2){

        } else if(choice == 3){
            ifstream file;
            string str;
            string name;
            string password;
            cout << "Enter new account name" << endl;
            cin >> name;
            while(getline(file, str)){
                
            }
            cout << "Enter new accoutn password" << endl;
            cin >> password;
            cout << "Welcome " << name << "!" << endl;

        }
    }
}