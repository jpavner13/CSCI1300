#include <iostream>
using namespace std;

class Ground{
    public:
        Ground(string type);

        string getGroundType();
        int setGroundType(string newGroundType);

        int getGroundIntensity();
        int setGroundIntensity(int newGroundType);

    private:
        string groundType;
        int groundIntensity;
};