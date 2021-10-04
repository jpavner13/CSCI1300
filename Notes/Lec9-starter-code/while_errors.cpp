#include <iostream>
using namespace std;

int main()
{
    // Error #1: 
    int i = 5;
    while(i > 0)
    {
        cout << i << endl;
        i++;
    }

    // Error #2: 
    // i = 5;
    // while(i < 0)
    // {
    //     cout << i << endl;
    //     i--;
    // }
    return 0;
}