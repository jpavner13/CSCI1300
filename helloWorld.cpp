#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;
int main(){
    system("clear");
    vector<char> characters;
    char HcharNum = 72;
    char echarNum = 101;
    char lcharNum = 108;
    char ocharNum = 111;
    char WcharNum = 87;
    char rcharNum = 114;
    char dcharNum = 100;
    for(int i = 10; i > 0; i--){
        if(i == 10){
            characters.push_back(HcharNum);
        }
        if(i == 9){
            characters.push_back(echarNum);
        }
        if(i == 8){
            characters.push_back(lcharNum);
        }
        if(i == 7){
            characters.push_back(lcharNum);
        }
        if(i == 6){
            characters.push_back(ocharNum);
        }
        if(i == 5){
            characters.push_back(WcharNum);
        }
        if(i == 4){
            characters.push_back(ocharNum);
        }
        if(i == 3){
            characters.push_back(rcharNum);
        }
        if(i == 2){
            characters.push_back(lcharNum);
        }
        if(i == 1){
            characters.push_back(dcharNum);
        }
    }
    char spaceChar = 32;
    bool stillPrinting = true;
    for(int i = 0; i < characters.size(); i++){
        if(stillPrinting){
            if(characters[i] == 'W'){
                cout << spaceChar;
            }
            cout << characters[i];
            if(characters[i] == dcharNum){
                stillPrinting = false;
            } else {
                stillPrinting = true;
            }
        }
    }
    int exclimationMarkNum = 33;
    cout << char(exclimationMarkNum);
    cout << endl;
    return 0;
    usleep(5000000);
}