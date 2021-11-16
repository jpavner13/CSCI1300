#include <iostream>
#include "Inventory.h"
using namespace std;

Inventory::Inventory(){
    name = "";
    type = "";
    orders = 0;
}
Inventory::Inventory(string newName, string newType, int newOrders){
    name = newName;
    type = newType;
    orders = newOrders;
}
string Inventory::getName(){
    return name;
}
void Inventory::setName(string newName){
    name = newName;
}
string Inventory::getType(){
    return type;
}
void Inventory::setType(string newType){
    type = newType;
}
int Inventory::getOrders(){
    return orders;
}
void Inventory::setOrders(int newOrders){
    orders = newOrders;
}
double Inventory::grossRevenue(double price){
    return (double(price) * orders);
}