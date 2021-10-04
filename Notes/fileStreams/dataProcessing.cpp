#include <iostream>
#include <ofstream>
#include <fstream>

int main(){
    ifstream in1;

    in1.open(test.txt);

    if(in1.fail()){
        cout << "File couldnt be opened" << endl;
        return -1;
    }

    string s;
    int var;
    char c;

    //in1 >> s1 >> s2;
    getline(in1, s);
    cout << s << endl;
    getline(in1, s);
    while(!in1.eof()){
        if(s.length() > 1){                 //!s.empty()
            total += stoi(s.substr(2));     // stoi(), stod(), string to int, string to double
            // Read data from file
            in1 >> c >> var;
            cout << c << " " << var << endl;
        }
    }
    cout << total;

    return 0;
}