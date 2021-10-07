#include <iostream>
using namespace std;

bool isVowel(char c){
    if((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')){
        return true;
    } else {
        return false;
    }
}

int insert(char str[], int numChar, int length, int vowels){
    if((numChar + vowels) > length){
        string s;
        for(int i = 0; i < numChar; i++){
            s += str[i];
        }
        cout << s << endl;
        return numChar;
    } else {
        string newString[length];
        for(int i = 0; i < numChar; i++){
            if(isVowel(str[i])){
                newString[i] = str[i];
                newString[i + 1] = (int(str[i]) - 32);
                i++;
                numChar++;
            } else {
                newString[i] = str[i];
            }
        }
        for(int i = 0; i < length; i++){
            cout << newString[i];
        }
        cout << endl;
        return numChar + vowels;
    }
}

int main(){
    char chars[16] = {'i','n','t','e','r','e','s','t','i','n','g'};
    insert(chars, 11, 16, 4);
    return 0;
}