#include <iostream>
#include "Pokemon.h"

using namespace std;

int main(){
    Pokemon pikachu("Pikachu", 20, 3, "electric", 10);
    pikachu.display();
    pikachu.set_hp(50);
    pikachu.dec_hp();
    pikachu.modify_hp_by(-4);
    pikachu.display();
    return 0;
}