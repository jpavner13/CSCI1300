#include <iostream>
using namespace std;

class GroceryList{
    public:
    GroceryList();
    int loadGroceryItems(string filename);
    int searchForCodes(string groceryCode);
    string getGroceryItem(string groceryCode);

    private:
    string groceries[50];
    string codes[50];
};