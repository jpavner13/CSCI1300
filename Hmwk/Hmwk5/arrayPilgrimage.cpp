#include <iostream>
using namespace std;

int main(){
    double distance[10];
    string pasta[] = {"Penne", "Bucatini", "Farfalle", "Fusilli", "Rigatoni"};
    int sequence[100];
    char letters[(26 * 2)];

    for(int i = 0; i < 10; i++){
        distance[i] = 42.42;
    }
    int current = 1;
    for(int i = 0; i < 100; i++){
        sequence[i] = current;
        current += 2;
    }
    int lowerCase = 97;
    int upperCase = 65;
    for(int i = 0; i < (26 * 2); i+= 2){
        letters[i] = upperCase;
        upperCase++;
        letters[i + 1] = lowerCase;
        lowerCase++;
    }
    for(int i = 0; i < 10; i++){
        cout << distance[i] << endl;
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << pasta[i] << endl;
    }
    cout << endl;
    for(int i = 0; i < 100; i++){
        cout << sequence[i] << endl;
    }
    cout << endl;
    for(int i = 0; i < (26 * 2); i++){
        cout << letters[i] << endl;
    }
    return 0;
}