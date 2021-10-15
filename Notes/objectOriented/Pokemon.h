#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using namespace std;

class Pokemon{
    public:
    //Initializer
    Pokemon();          
    Pokemon(string n, int h, int e, string t, int b);

    //mutators/setters
    void set_name(string n);
    void set_hp(int hitPoints);
    void set_evolution(int ev);
    void set_type(string t);
    void set_battles_num(int num);

    //accessors/getters
    string get_name();
    int get_hp();
    int get_evolution();
    string get_type();
    int get_battles_num();

    //other member functions
    void inc_hp();
    void dec_hp();
    void modify_hp_by(int num);
    void display() const;
    bool battle(Pokemon b);
    void check_evolution();

    private:
    string name;
    int hp;
    int evolution;
    string type;
    int battles_num;
};

// Dont inplament functions in .h file

#endif