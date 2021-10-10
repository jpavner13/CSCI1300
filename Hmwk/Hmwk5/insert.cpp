// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 5 - Problem #3

#include <iostream>
#include <array>
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
        char s[numChar];
        for(int i = 0; i < numChar; i++){
            s[i] = str[i];
        }
        for(int i = 0; i < length; i++){
            str[i] = s[i];
        }
        return numChar;
    } else {
        char str2[numChar + vowels];
        int count = 0;
        for(int i = 0; i < numChar; i++){
            if(isVowel(str[i])){
                str2[count] = str[i];
                str2[count + 1] = int(str[i]) - 32;
                count += 2;
            } else {
                str2[count] = str[i];
                count++;
            }
        }
        for(int i = 0; i < length; i++){
            str[i] = str2[i];
        }
        //int len = sizeof(str2) / sizeof(str2[0]);
        return numChar + vowels;
    }
}

int main(){
    char chars[16] = {'i','n','t','e','r','e','s','t','i','n','g'};
    insert(chars, 11, 16, 4);
    return 0;
}