#include <iostream>
using namespace std;

class Menu{
    public:
        Menu();

        string getMenuOptionAt(int index);
        int setMenuOptionNameAt(int index, string optionName);

        string getGameName();
        int setGameName(string newGameName);

        int getChoice();

        void printMenu();

    private:
        static const int numOptions = 4;
        string options[numOptions];
        string gameName;
};