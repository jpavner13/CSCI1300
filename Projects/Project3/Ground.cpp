#include <iostream>
#include "Ground.h"
using namespace std;

Ground::Ground(string type){
    groundType = type;
}
string Ground::getGroundType(){
    return groundType;
}
int Ground::setGroundType(string newGroundType){
    groundType = newGroundType;
    return 0;
}
int Ground::getGroundIntensity(){
    return groundIntensity;
    return 0;
}
int Ground::setGroundIntensity(int newGroundIntensity){
    groundIntensity = newGroundIntensity;
    return 0;
}