#include "Ring.h"
#include "Player.h"

using namespace std; 

int main() {
    Ring ring;  // create object called map of type Map
    
    char move;  // for storing user input

    // quit after 10 moves
    for(int i = 0; i < 10; i++) {
        ring.displayMap();  // pretty print map_data in terminal

        cout << "Valid moves are: " << endl; 
        Player player1;
        ring.displayMoves(player1, 1);  // give user a menu of valid moves to pick from
        
        cout << "Input a move: "; 
        cin >> move;
        cout << endl;
        ring.executeMove(move, 1);  // move the player on map based on user input

    }
}
