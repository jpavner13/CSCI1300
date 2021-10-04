// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 1 - Problem #7

/*
    make bool to represent if players are still playing
    while players are playing, display menu
    if choice = 1, prompt user to enter inputs
    if inputs are correct, call calcLikenessScore()
    if not, generate error
    if choice is 2, prompt user for correct inputs
    find longest string, and call function acordingly
    if choice is 3, prompt for correct inputs
    play game with user, and display winner
    if coice is 4
    set bool to false, 
    quit
    else print invalad input
    loop through until user quits
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

double bestLikenessScore(string seq1, string gold_seq){
    if(seq1.length() < gold_seq.length()){
        return (-1);
    }

    double highScore = 0;
    for(int i = 0; i < (seq1.length() - (gold_seq.length() - 2)); i += 2){
        string compare = seq1.substr(i, gold_seq.length());
        //cout << compare << endl;
        if(calcLikenessScore(compare, gold_seq) > highScore){
            highScore = calcLikenessScore(compare, gold_seq);
        }
    }
    //cout << highScore << endl;
    return highScore;
}

void findWinner(string seq1, string seq2, string seq3, string gold_seq){
    double seq1Score = bestLikenessScore(seq1, gold_seq);
    double seq2Score = bestLikenessScore(seq2, gold_seq);
    double seq3Score = bestLikenessScore(seq3, gold_seq);

    if((seq1Score == 0) && (seq2Score == 0) && (seq3Score == 0)){
        cout << "Better luck next time everyone!" << endl;
    } else if((seq1Score > seq2Score) && (seq1Score > seq3Score)){
        cout << "Congratulations Player 1! You have won!" << endl;
    } else if ((seq2Score > seq1Score) && (seq2Score > seq3Score)){
        cout << "Congratulations Player 2! You have won!" << endl;
    } else if ((seq3Score > seq1Score) && (seq3Score > seq2Score)){
        cout << "Congratulations Player 3! You have won!" << endl;
    } else if ((seq1Score == seq2Score) && (seq2Score == seq3Score)){
        cout << "Congratulations everyone! You have all won!" << endl;
    } else if ((seq1Score == seq2Score) && (seq2Score > seq3Score)){
        cout << "Congratulations Players 1 and 2! You have won!" << endl;
    } else if ((seq2Score == seq3Score) && (seq3Score > seq1Score)){
        cout << "Congratulations Players 2 and 3! You have won!" << endl;
    } else if ((seq1Score == seq3Score) && (seq3Score > seq2Score)){
        cout << "Congratulations Players 1 and 3! You have won!" << endl;
    } else {
        cout << "Error, check inputs" << endl;
    }
}

int main(){
    bool playing = true;
    while(playing){
        int choice;
        cout << "----Menu!----" << endl;
        cout << "Choice 1: Calculate the Likeness Score between 2 strings of equal length." << endl;
        cout << "Choice 2: Calculate the Best Likeness Score between 2 sequences of possibly different length." << endl;
        cout << "Choice 3: Find winner among sequences of 3 players and a Golden Sequence." << endl;
        cout << "Choice 4: Exit." << endl;
        cout << "Enter your choice (1-4):" << endl;
        cin >> choice;

        switch(choice){
            case 1: {
                string seqH, seqK;
                cout << "Enter Sequence 1" << endl;
                cin >> seqH;
                cout << "Enter Sequence 2" << endl;
                cin >> seqK;
                if(calcLikenessScore(seqH, seqK) == -1){
                    cout << "Invalid input. Sequences of different length." << endl;
                } else {
                    cout << "Score: " << calcLikenessScore(seqH, seqK) << endl;
                }
                break;
            }
            case 2: {
                string seqX, seqY;
                cout << "Enter Sequence 1" << endl;
                cin >> seqX;
                cout << "Enter Sequence 2" << endl;
                cin >> seqY;
                if(seqX.length() > seqY.length()){
                    cout << "Best Likeness Score: " << bestLikenessScore(seqX, seqY) << endl;
                } else {
                    cout << "Best Likeness Score: " << bestLikenessScore(seqY, seqX) << endl;
                }
                break;
            }
            case 3: {
                string seqA, seqB, seqC, gold_seq;
                cout << "Enter Sequence of Player 1" << endl;
                cin >> seqA;
                cout << "Enter Sequence of Player 2" << endl;
                cin >> seqB;
                cout << "Enter Sequence of Player 3" << endl;
                cin >> seqC;
                cout << "Enter Golden sequence" << endl;
                cin >> gold_seq;
                findWinner(seqA, seqB, seqC, gold_seq);
                break;
            }
            case 4: {
                playing = false;
                cout << "Exiting." << endl;
                break;
            }
            default: 
                cout << "Invalid Input. Choices between 1-4." << endl;
        }
    }
}