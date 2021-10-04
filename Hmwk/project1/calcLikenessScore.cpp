// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 1 - Problem #4

/*
    go through both strings and push every two chars in each string into an array for each string (each array will now be split into cards)
    create counter for same suit
    create counter for bonus
    compare the first char to see if the suit is the same
    if it is, increase counter and test to see if the rank is the same
    if the rank is also the same, increase bonus by 1
    calculate score using counters and length of arrays
    return score
*/

#include <iostream>
using namespace std;

bool sameSuit(string s1, string s2){
    bool sameSuit = false;
    if(s1.substr(0,1) == s2.substr(0,1)){
        sameSuit = true;
        return sameSuit;
    } else {
        return sameSuit;
    }
}

bool sameCard(string s1, string s2){
    bool sameCard = false;
    if(s1.substr(1,1) == s2.substr(1,1)){
        sameCard = true;
        return sameCard;
    } else {
        return sameCard;
    }
}

double calcLikenessScore(string seq1, string seq2){
    string array1[(seq1.length() / 2)];
    string array2[(seq2.length() / 2)];
    int count = 0;

    if(seq1.length() != seq2.length()){
        return (-1);
    }

    for(int i = 0; i <= seq1.length() - 2; i += 2){
        string sub1 = seq1.substr(i, 2);
        array1[count] = sub1;
        string sub2 = seq2.substr(i, 2);
        array2[count] = sub2;
        count++;
    }

    int length = (seq1.length() / 2);
    double numSuit = 0;
    double bonus = 0;

    for(int i = 0; i < length; i++){
        if(sameSuit(array1[i], array2[i])){
            numSuit++;
            if(sameCard(array1[i], array2[i])){
                bonus++;
            }
        }
    }

    double likenessScore = (numSuit / length) + bonus;
    return likenessScore;
}