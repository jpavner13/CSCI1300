#include <iostream>
using namespace std;

int main(){
    string firstName, lastName, space;
    firstName = "Pierce";
    lastName  = "Avner";

    cout << firstName << " " << lastName << endl;

    //Concatination
    string fullName;
    space = " ";
    fullName = firstName + space + lastName;

    cout << fullName << endl;

    //Length of a string
    int nameLength = fullName.length();
    cout << nameLength << endl;

    /*
        Index chars in strings

        P  I  E  R  C  E     A  V  N  E  R
        0  1  2  3  4  5  6  7  8  9  10 11

        Youll notice fullName.length(); returns 12. length() starts counting at 1, while indexes start at 0

        accesing:
        fullName[index#]
    */

   cout << "fullName[0] is " << fullName[0] << endl;
   cout << "fullName[5] is " << fullName[5] << endl;

   //fullName[15]; //Value doesnt exist, will store an empty value

   cout << fullName.find("c") << endl;
   cout << fullName.find("e") << endl;
   cout << fullName.find("e" , 8) << endl;                          //The number tells the computer to look for an "e" after index 8
   cout << fullName[fullName.find("c")] << endl;

   //Substrings

   cout << fullName.substr(0, 3) << endl;                           // ints are (startingValue, length)

    return 0;
}