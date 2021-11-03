// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 1 - Problem #5

/*
    create int for high score
    go through each possible segment in the given sequence
    calculate likenessScore for segment
    if the new likeness score is greater than the current one, set new score to be the new highest
    go through all possibilities
    return the highest score
*/

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