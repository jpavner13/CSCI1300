#include <iostream>
#include <vector>
using namespace std;

class Inventory{
    public:
    Inventory();
    Inventory(string newName, string newType, int newOrders);

    string getName();
    void setName(string newName);

    string getType();
    void setType(string newType);

    int getOrders();
    void setOrders(int newOrders);

    double grossRevenue(double price);

    private:
    string name;
    string type;
    int orders;
};