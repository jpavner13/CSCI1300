#include <iostream>
using namespace std;

void printArray(int a[][3], int row, int column){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    double values[10];     //type, name, size

    double numbers[] = {32, 54, 67.5, 29, 35, 80, 115, 44.5, 100, 65};

    numbers[3] = 0;

    //declare array
    int val[10];

    //initialize array
    val[0] = 10;
    val[1] = 20;
    val[2] = 30;
    val[3] = 40;

    int count = 50;
    for(int i = 4; i < 10; i++){
        val[i] = count;
        count += 10;
    }

    //print array
    cout << val[3] << endl;

    for(int i = 0; i < 10 ; i++){
        cout << val[i] << endl;
    }


    // 2D arrays

    //int couts[rows][columbs];    //Rows doesnt need to be defined at definition, coulumbs do

    const int COUNTRIES = 8;
    const int COLUMNS = 3;
    int medals[COUNTRIES][COLUMNS];
    int arr[COUNTRIES];
    string col1[COUNTRIES] = {"Canada", "China", "Germany", "Korea", "Japan", "Russia", "United States"};

    for(int i = 0; i < COUNTRIES; i++){
        for(int j = 0; j < COLUMNS; j++){
            medals[i][j] = 0;
        }
    }
    printArray(medals, COUNTRIES, COLUMNS);

    // 3D arrays
    int color[30][30][30];

    return 0;
}