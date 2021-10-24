// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 7 - Problem EC

#include <iostream>
using namespace std;

string keywordCipher(string message, string key, bool isEncript){
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    if(isEncript){
        int length = key.length();
        char keyArr[26];
        int count = 0;
        int countAppend = 0;
        for(int i = 0; i < length; i++){
            bool isInKey = true;
            for(int x = 0; x < 26; x++){
                char s = key[i];
                if(s == keyArr[x]){
                    isInKey = false;
                }
            }
            if(isInKey && key[i] != ' '){
                keyArr[count] = key[i];
                count++;
                countAppend++;
            }
        }
        for(int i = 25; i >= 0; i--){
            bool add = true;
            for(int x = 0; x < length; x++){
                if(alphabet[i] == key[x]){
                    add = false;
                }
            }
            if(add){
                keyArr[countAppend] = alphabet[i];
                countAppend++;
            }
        }

        string returnMessage = "";
        for(int i = 0; i < message.length(); i++){
            char c = message[i];
            if(c == ' '){
                returnMessage += " ";
            } else {
                for(int x = 0; x < 26; x++){
                    if(c == alphabet[x]){
                        returnMessage += keyArr[x];
                    }
                }
            }
        }
        //cout << returnMessage << endl;
        return returnMessage;
    } else {
        int length = key.length();
        char keyArr[26];
        int count = 0;
        int countAppend = 0;
        for(int i = 0; i < length; i++){
            bool isInKey = true;
            for(int x = 0; x < 26; x++){
                char s = key[i];
                if(s == keyArr[x]){
                    isInKey = false;
                }
            }
            if(isInKey && key[i] != ' '){
                keyArr[count] = key[i];
                count++;
                countAppend++;
            }
        }
        for(int i = 25; i >= 0; i--){
            bool add = true;
            for(int x = 0; x < length; x++){
                if(alphabet[i] == key[x]){
                    add = false;
                }
            }
            if(add){
                keyArr[countAppend] = alphabet[i];
                countAppend++;
            }
        }

        string returnMessage = "";
        for(int i = 0; i < message.length(); i++){
            char c = message[i];
            if(c == ' '){
                returnMessage += " ";
            } else {
                for(int x = 0; x < 26; x++){
                    if(c == keyArr[x]){
                        returnMessage += alphabet[x];
                    }
                }
            }
        }
        //cout << returnMessage << endl;
        return returnMessage;
    }
}

int main(){
    keywordCipher("ZOMBIE HERE", "SECRET", true);
    keywordCipher("ANPEWT XTKT", "SECRET", false);
    string s = keywordCipher("P MPHNFQLHW TL MFNQFJM", "PINK FLOYD", false);
    cout << s << endl;
    return 0;
}