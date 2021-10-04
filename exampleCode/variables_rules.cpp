#include <iostream>

using namespace std;

int main(){
    /*
    data types:
        boolean (bool): T or F, 1 or 0
        char: 1 letter, 1 int
        int: Whole number (+ or -), 4 bytes of memory
        float: decimal number
        double:
        string: Sentences, words, etc.
    */

   //Variable declaration
    bool var1;  // 1 bit

    //Variable initialization
    var1 = 0;

    bool var2;

    var2 = 1;

    //char -> 1 byte
    char var3 = 'C';
    char var4 = 'cat'; //will just store "c"

    //string
    string string1 = "cat";

    // integers
    // short int (2 bytes)
    // int (4 bytes: max value is 2,147,483,647)
    // long int (8 bytes)
    // unsigned int (4 bytes, only +)
    // unsigned long int (8 bytes, only +)
    // float (4 bytes, 7 decimal didgets of precision)
    // double (8 bytes, 15 decimal didgets of precision)
    // long double (16 bytes, ~30 didgets of precision)

    int num1 = 10;
    int num2;
    num2 = num1 + 10;

    unsigned int num3 = 10;

    //Rules for declaration:
    // Must start with a char or a "_", cannot start with a #
    // cannot use a reserved word as a name (float, int, new, class, if, etc.)
    // some symbols are not allowed "/" and "." are a few examples
    // inintial value MUST match variable type
    // Use meaningful names (camelCase - first word lowercase, each new word uppercase)

    // Type casting - changing variable types

    int num10 = 12.67; //Will only store 12, rest will be trunkated

    num10 = (int)105.7;
    num10 = static_cast<int> (105.7);

    // constants (any data type)
    // convention to name constants in all caps
    // Cannot modify the value of a constant variable

    const int PRICE = 10;

    PRICE = PRICE * 10; //Will not compile
    PRICE = 75; //Will not compile

}