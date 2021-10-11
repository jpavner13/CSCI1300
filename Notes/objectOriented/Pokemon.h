#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using namespace std;

class Pokemon{
    public:             
    //mutators/setters
    void set_name(string n);
    void set_hp(int hitPoints);
    void set_evolution(int ev);
    void set_type(string t);

    //accessors/getters
    string get_name();
    int get_hp();
    int get_evolution();
    string get_type();

    private:
    string name;
    int hp;
    int evolution;
    string type;
};

// Dont inplament functions in .h file

#endif