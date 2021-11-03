#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateCard(){
    string suit, rank;
    int suitRank = (rand() % 4) + 1;
    switch(suitRank){
        case 1:
            suit = "H"; break;
        case 2:
            suit = "D"; break;
        case 3:
            suit = "C"; break;
        case 4:
            suit = "S"; break;
    }
    int rankRank = (rand() % 13) + 1;
    switch(rankRank){
        case 1:
            rank = "A"; break;
        case 11:
            rank = "J"; break;
        case 12:
            rank = "Q"; break;
        case 13:
            rank = "K"; break;
        default:
            rank = to_string(rankRank); break;
    }
    string card = suit + rank;
    return card;
}

string generateSequence(int numCards){
    string cards;
    for(int i = 0; i < numCards; i++){
        cards = cards + generateCard();
    }
    return cards;
}

int main(){
    cout << generateSequence(5) << endl;
}