#include <iostream>

using namespace std;

int main(){
    cout << "Hello, World! Hello CSCi 1300" << endl;
    return 0;
}

/* #include <iostream> : tells the compiler to include a service for "stream input/output" 

    using namespace std; : tells the compiler to use the "standard namespace" used in conjunction with IOstream for controling input and output
        (different way of storing implimentations)

    int main(){} : defines the main function (int is our data type)

    cout << "Hello, World!" << endl; : Output statement

    return 0; : Return statement


    Errors:
        Compile time error: find at the time of compilation (Syntax/ language rules)
        Run-Time errors: during exicution(logical flaws, exceptions(1 / 0), etc.)


    How to compile and run code in terminal:
        jackavner$ g++ -std=c++11 "filename.cpp"
        jackavner$ ./a.out   // Can rename a.out with "g++ -std=c++11 "filename.cpp" -o "exicutable file name"

*/