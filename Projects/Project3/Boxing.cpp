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
//#include "Fighter.h"
#include "Ground.h"
#include "Menu.h"

int main(){
    Player player1 = Player("Bill", "Password");
    Fighter fighter1 = Fighter("Sal", 500, 3);
    Ground ground1 = Ground("Earth");
    Menu menu1 = Menu();

    cout << player1.getPlayerName() << endl;
    cout << player1.getPlayerPassword() << endl;
    cout << player1.getPlayerAccountBalance() << endl;

    cout << fighter1.getFighterName() << endl;
    cout << fighter1.getFightsWon() << endl;
    cout << fighter1.getHp() << endl;
    cout << fighter1.getLevel() << endl;
    cout << fighter1.getPower() << endl;

    cout << ground1.getGroundType() << endl;
    ground1.setGroundIntensity(5);
    cout << ground1.getGroundIntensity() << endl;

    menu1.setGameName("Boxing");
    cout << menu1.getGameName() << endl;
}