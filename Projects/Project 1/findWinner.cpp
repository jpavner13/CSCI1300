// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Project 1 - Problem #6

/*
    calculate likenessScore for each players sequences
    check to see if all scores are 0
    if they are, return that there are no winners
    compare each score to see if there is one overall winner
    if there is, return that winner
    if not, compare to see if there are two winners
    if there is, return which two players won
    if not, compare to see if there are three winners
    if there are, congradualate all players

*/

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