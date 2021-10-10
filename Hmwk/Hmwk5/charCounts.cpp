#include <iostream>
using namespace std;

int char_count(string str){
    int count = 0;
    int letters[52];
    for(int i = 0; i < 52; i++){
        letters[i] = 0;
    }
    int length = str.length();
    for(int i = 0; i <= length; i++){
        char c = str[i];
        int value = int(c);
        if(value > 90){
            value -= 6;
        }
        letters[(value - 65)]++;
    }
    /*
    for(int i = 0; i < 52; i++){
        cout << letters[i] << endl;
    }
    */
    for(int i = 0; i < 52; i++){
        if(letters[i] > 0){
            count++;
            char letter = (i + 65);
            if(int(letter) > 90){
                letter = letter + 6;
            }
            //cout << letter << ": " << letters[i] << endl;
        }
    }
    string listLetters[count];
    int current = 0;
    for(int i = 0; i < 52; i++){
        if(letters[i] > 0){
            string add = "";
            char letter = (i + 65);
            if(int(letter) > 90){
                letter = letter + 6;
            }
            add += letter;
            add += ": ";
            int num = letters[i];
            std::string s = std::to_string(num);
            add += s;
            listLetters[current] = add;
            //cout << letter << ": " << letters[i] << endl;
            current++;
        }
    }
    for(int i = 0; i < count; i++){
        cout << listLetters[i] << endl;
    }
    //cout << count << endl;
    return count;
}

int main(){
    char_count("Colorado");
    return 0;
}