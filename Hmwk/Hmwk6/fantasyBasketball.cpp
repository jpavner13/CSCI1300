// CS1300 Spring 2021
// Author: Jack (Pierce) Avner
// Recitation: 117 – Naga Sai Meenakshi Sistla
// Homework 6 - Problem #3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int split(string str, char sep, string arr[], int arrSize){
    string current = "";
    int count = 1;
    if(str.length() < 1){
        count = 0;
    }
    int arrCurrent = 0;
    int length = str.length();
    for(int i = 0; i < length; i++){
        if(str[i] == sep){
            arr[arrCurrent] = current;
            current = "";
            arrCurrent++;
            count++;
        } else {
            current += str[i];
        }
    }
    if(arrSize < count){
        count = -1;
    }
    arr[arrCurrent] = current;
    return count;
}

int calcStarterPercent(int FGA, int FTA, int TOV, int TMMP, int MP, int TMFGA, int TMFTA, int TMTOV){
    double fga = double(FGA);
    double fta = double(FTA);
    double tov = double(TOV);
    double tmmp = double(TMMP);
    double mp = double(MP);
    double tmfga = double(TMFGA);
    double tmfta = double(TMFTA);
    double tmtov = double(TMTOV);

    double numerator = ((.44 * fta) + fga + tov) * (tmmp / 5.0);
    double denominator = ((.44 * tmfta) + tmfga + tmtov) * (mp);
    int usg = int(100 * (numerator / denominator));
    //cout << usg << endl;
    return usg;
}

int calcBenchPercent(int PTS, int FGA, int FTA){
    double pts = double(PTS);
    double fga = double(FGA);
    double fta = double(FTA);
    double tsa = ((.44 * fta) + fga);
    double ts = (pts / (2.0 * tsa));
    //cout << ts << endl;
    return int(100 * ts);
}

void print(string steam[], string bteam[], bool enoughStart, bool enoughBench){
    cout << "Selected players:" << endl;
    for(int i = 1; i < 10; i++){
        cout << steam[i] << ", starter, " << steam[i + 1] << endl;
        i += 2;
    }
    for(int i = 1; i < 6; i++){
        cout << bteam[i] << ", bench, " << bteam[i + 1] << endl;
        i += 2;
    }
    if(enoughStart || enoughBench){
        cout << "Great, your team is ready!" << endl;
    } else {
        cout << "Notenoughplayerswhosatisfy the criteria to form a team!" << endl;
    }
}

int main(){
    ifstream fileStarters;
    ifstream filesBench;
    string startFile, benchFile;
    cout << "Enter the filename of starters:" << endl;
    cin >> startFile;
    cout << "Enter the filename of bench players:" << endl;
    cin >> benchFile;

    fileStarters.open(startFile);
    filesBench.open(benchFile);

    string startersTeam[10];
    string benchTeam[6];

    int playersCount = 1;
    int benchPlayers = 1;

    bool start = false;
    bool bench = false;

    if(fileStarters.is_open() && filesBench.is_open()){
        string str = "";
        int startPlayers = 0;
        while(getline(fileStarters, str)){
            if(str.length() != 0){
                string statsArray[15];
                split(str, ',', statsArray, 15);
                /*
                for(int i = 0; i < 14; i++){
                    cout << statsArray[i] << " ";
                }
                */
                //cout << endl;
                string fga      = statsArray[4];
                //cout << "fga " << fga << endl;
                string fta      = statsArray[8];
                //cout << "fta " << fta << endl;
                string tov      = statsArray[9];
                //cout << "tov " << tov << endl;
                string tmmp     = statsArray[10];
                //cout << "tmmp " << tmmp << endl;
                string mp       = statsArray[2];
                //cout << "mp " << mp << endl;
                string tmfga    = statsArray[11];
                //cout << "tmfga " << tmfga << endl;
                string tmfta    = statsArray[12];
                //cout << "tmfta " << tmfta << endl;
                string tmtov    = statsArray[13];
                //cout << "tmtov " << tmtov << endl;
                int FGA      = stoi(fga);
                int FTA      = stoi(fta);
                int TOV      = stoi(tov);
                int TMMP     = stoi(tmmp);
                int MP       = stoi(mp);
                int TMFGA    = stoi(tmfga);
                int TMFTA    = stoi(tmfta);
                int TMTOV    = stoi(tmtov);
                int usg = calcStarterPercent(FGA, FTA, TOV, TMMP, MP, TMFGA, TMFTA, TMTOV);
                
                if(startPlayers < 5){
                    if(usg > 28){
                        startersTeam[playersCount] = statsArray[0];
                        startersTeam[playersCount + 1] = statsArray[1];
                        playersCount += 2;
                        startPlayers++;
                    }
                }
            }
        }
        if(startPlayers < 5){
            start = true;
        }
    } else {
        cout << "Could not open file(s)." << endl;
    }
    if(filesBench.is_open()){
        string str;
        int totalPlayers = 0;
        while(getline(filesBench, str)){
            string statsArray[5];
            split(str, ',', statsArray, 5);

            string pts = statsArray[2];
            //cout << statsArray[2] << endl;
            string fga = statsArray[3];
            string fta = statsArray[4];
            int PTS = stoi(pts);
            //cout << PTS << endl;
            int FGA = stoi(fga);
            int FTA = stoi(fta);

            int currentPercent = calcBenchPercent(PTS, FGA, FTA);
            //cout << currentPercent << endl;

            if(totalPlayers < 3){
                if(currentPercent > 50){
                    int l = benchPlayers;
                    benchTeam[l] = statsArray[0];
                    //cout << statsArray[0] << endl;
                    benchTeam[l + 1] = statsArray[1];
                    //cout << statsArray[1] << endl;
                    benchPlayers += 2;
                    totalPlayers++;
                }
            }
        }  
        if(totalPlayers < 3){
            bench = true;
        } 
    } else {
        cout << "Could not open file(s)." << endl;
    }

    print(startersTeam, benchTeam, start, bench);
    return 0;
}