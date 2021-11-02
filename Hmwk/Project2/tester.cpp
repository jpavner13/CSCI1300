#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Paste your program here, but do NOT paste your #include statements or using namespace std;
string lowerCase(string str){
    string returnString = "";
    for(int i = 0; i < str.length(); i++){
        char c = str[i];
        int val = c;
        if(val > 64 && val < 91){
            char newChar = val + 32;
            returnString += newChar;
        } else {
            returnString += c;
        }
    }
    return returnString;
}

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

class Song{
    public:
    Song();
    Song(string title, string artist, string genre);

    string getTitle();
    void setTitle(string newTitle);
    string getArtist();
    void setArtist(string newArtist);
    string getGenre();
    void setGenre(string newGenre);

    int countGenre(string genre, Song arr[], int numStored);
    int readSongs(string fileName, Song arr[], int numSongsStored, int arrSize);
    void printAllSongs(Song arr[], int numStored);
    int frequentGenreSongs(Song arr[], int numSongStored);

    private:
    string title;
    string artist;
    string genre;
};

Song:: Song(){
    title = "";
    artist = "";
    genre = "";
}

Song::Song(string t, string a, string g){
    title = t;
    artist = a;
    genre = g;
}

string Song::getArtist(){
    return artist;
}
void Song::setArtist(string s){
    artist = s;
}

string Song::getTitle(){
    return title;
}
void Song::setTitle(string s){
    title = s;
}

string Song::getGenre(){
    return genre;
}
void Song::setGenre(string s){
    genre = s;
}

int countGenre(string genre, Song arr[], int numStored){
    int count = 0;
    for(int i = 0; i < numStored; i++){
        string str = lowerCase(arr[i].getGenre());
        if(str == lowerCase(genre)){
            count++;
        }
    }
    return count;
}

int readSongs(string fileName, Song arr[], int numSongsStored, int arrSize){
    ifstream file;
    file.open(fileName);
    string str;

    int indexCounter = numSongsStored;

    if(numSongsStored >= arrSize){
        return -2;
    }

    if(file.is_open()){
        while(getline(file, str)){
            if(str.length() != 0){
                Song currentSong;
                string currentLine[3];
                split(str, ',', currentLine, 3);
                currentSong.setArtist(currentLine[1]);
                currentSong.setTitle(currentLine[0]);
                currentSong.setGenre(currentLine[2]);
                arr[indexCounter] = currentSong;
                indexCounter++;
            }
            if(indexCounter == arrSize){
                return indexCounter;
            }
        }
        return indexCounter;
    } else {
        return -1;
    }
}

void printAllSongs(Song arr[], int numStored){
    if(numStored <= 0){
        cout << "No songs are stored" << endl;
    } else {
        cout << "Here is a list of songs" << endl;
        for(int i = 0; i < numStored; i++){
            string artist = arr[i].getArtist();
            string title = arr[i].getTitle();
            cout << title << " is by " << artist << endl;
        }
    }
}

int frequentGenreSongs(Song arr[], int numSongStored){
    Song songs[50];
    for(int i = 0; i < numSongStored; i++){
        songs[i] = arr[i];
    }
    int max;
    for(int i = 0; i < numSongStored; i++){
        int currentMax = 0;
        string currentGenre = songs[i].getGenre();
        for(int x = 0; x < numSongStored; x++){
            if(songs[x].getGenre() == currentGenre){
                currentMax++;
            }
        }
        if(currentMax > max){
            max = currentMax;
        }
    }
    return max;
}

class Listener{
    public:
    Listener();
    Listener(string nameSet, int plays[], int sizeArr);

    string getListenerName();
    void setListenerName(string newName);

    int getPlayCountAt(int i);
    bool setPlayCountAt(int index, int newInt);

    int totalPlayCount();

    int getNumUniqueSongs();

    int getSize();
    
    int addListener(string name, Listener listeners[], int numSongs, int numListenersStored, int listenerArrSize);
    int readListenerInfo(string fileName, Listener listeners[], int numListenersStored, int listenerArrSize, int maxCol);
    int getListenerStats(string name, Listener listeners[], int numListenersStored, int numSongs);
    
    private:
    string name;
    static const int size = 50;
    int playCount[size];
};

Listener:: Listener(){
    name = "";
    for(int i = 0; i < size; i++){
        playCount[i] = 0;
    }
}
Listener:: Listener(string nameSet, int plays[], int sizeArr){
    name = nameSet;
    for(int i = 0; i < sizeArr; i++){
        playCount[i] = plays[i];
    }
    for(int i = sizeArr; i < 50; i++){
        playCount[i] = 0;
    }
}

string Listener::getListenerName(){
    return name;
}

void Listener::setListenerName(string newName){
    name = newName;
}

int Listener::getPlayCountAt(int i){
    if(i <= size && i >= 0){
        return playCount[i];
    } else {
        return -1;
    }
}
bool Listener:: setPlayCountAt(int index, int newInt){
    if(index <= size && index >= 0 && newInt > 0){
        playCount[index] = newInt;
        return true;
    } else {
        return false;
    }
}

int Listener::getSize(){
    return size;
}

int Listener::totalPlayCount(){
    int total = 0;
    for(int i = 0; i < size; i++){
        total += playCount[i];
    }
    return total;
}

int Listener::getNumUniqueSongs(){
    int num = 0;
    for(int i = 0; i < size; i++){
        if(playCount[i] >= 1){
            num++;
        }
    }
    return num;
}

int addListener(string name, Listener listeners[], int numSongs, int numListenersStored, int listenerArrSize){
    if(name.length() == 0){
        return -3;
    }
    for(int i = 0; i < numListenersStored; i++){
        if(lowerCase(listeners[i].getListenerName()) == lowerCase(name)){
            return -2;
        }
    }
    Listener newListener;
    newListener.setListenerName(name);
    if(listenerArrSize > numListenersStored){
        listeners[numListenersStored] = newListener;
        numListenersStored++;
    } else {
        return -1;
    }
    return numListenersStored;
}

int readListenerInfo(string fileName, Listener listeners[], int numListenersStored, int listenerArrSize, int maxCol){
    if(numListenersStored >= listenerArrSize){
        return -2;
    }
    ifstream file;
    file.open(fileName);
    bool isEmpty = true;
    if(file.is_open()){
        string str;
        while(getline(file, str)){
            if(numListenersStored < listenerArrSize){
                if(str.length() != 0){
                    isEmpty = false;
                    string vals[maxCol];
                    int numCols = split(str, ',', vals, maxCol);
                    string name = vals[0];
                    int listens[numCols - 1];
                    for(int i = 0; i < (numCols - 1); i++){
                        listens[i] = stoi(vals[i + 1]);
                    }
                    Listener listener = Listener(name, listens, (numCols - 1));
                    listeners[numListenersStored] = listener;
                    numListenersStored++;
                }
            }
        }
    } else {
        return -1;
    }
    if(isEmpty){
        return 0;
    }
    return numListenersStored;
}

int getListenerStats(string name, Listener listeners[], int numListenersStored, int numSongs){
    bool inList = false;
    for(int i = 0; i < numListenersStored; i++){
        if(listeners[i].getListenerName() == name){
            inList = true;
            int uniqueSongs = listeners[i].getNumUniqueSongs();
            int totalPlays = 0;
            for(int x = 0; x < numSongs; x++){
                totalPlays += listeners[i].getPlayCountAt(x);
            }
            string listenerName = listeners[i].getListenerName();
            double average = double(totalPlays) / double(uniqueSongs);
            if(average > 0){
                cout << listenerName << " listened to " << uniqueSongs << " songs." << endl;
                cout << listenerName << "'s average number of listens was " << fixed << setprecision(2) << average << endl;
                return 1;
            } else {
                cout << listenerName << " has not listened to any songs." << endl;
                return 0;
            }
        }
    }
    if(!inList){
        cout << name << " does not exist." << endl;
        return -3;
    }
    return 0;
}

void printOptions(){
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read songs from file" << endl;
    cout << "2. Print all songs" << endl;
    cout << "3. Song-count by genre" << endl;
    cout << "4. Songs from most common genre" << endl;
    cout << "5. Add listener" << endl;
    cout << "6. Read listens from file" << endl;
    cout << "7. Get number of listens by a listener" << endl;
    cout << "8. Get listener statistics" << endl;
    cout << "9. Quit" << endl;
}

int main(){
    Song songs[50];
    Listener listeners[100];
    int numSongs = 0;
    int numListeners = 0;
    int input = 0;
    while(input != 9){
        printOptions();
        cin >> input;
        switch(input){
            case 1: {
                    string fileName;
                    cout << "Enter a song file name:" << endl;
                    cin >> fileName;
                    int totalSongs = readSongs(fileName, songs, numSongs, 50);
                    if(totalSongs == -1){
                        cout << "No songs saved to the database." << endl;
                    } else if (totalSongs == -2){
                        cout << "Database is already full. No songs were added." << endl;
                    } else {
                        cout << "Total songs in the database: " << totalSongs << endl;
                        numSongs = totalSongs;
                        if(numSongs >= 50){
                            cout << "Database is full. Some songs may have not been added." << endl;
                        }   
                    }
                }
                break;
            case 2:
                printAllSongs(songs, numSongs);
                break;
            case 3: {
                    string genre;
                    cout << "Genre:" << endl;
                    cin >> genre;
                    int totGenre = countGenre(genre, songs, numSongs);
                    cout << "Total " << genre << " songs in the database: " << totGenre << endl;
                    break;
                }
            case 4: {
                    int commonGenre = frequentGenreSongs(songs, numSongs);
                    cout << "Number of songs in most common Genre: " << commonGenre << endl;
                    break;
                }
            case 5: {
                    string currentName = "";
                    cout << "Enter a listener name:" << endl;
                    cin.ignore(1000, '\n');
                    getline(cin, currentName);
                    int add = addListener(currentName, listeners, 50, numListeners, 100);
                    if(add == -1){
                        cout << "Database is already full. Listener cannot be added." << endl;
                    } else if(add == -2){
                        cout << "Listener already exists." << endl;
                    } else if(add == -3){
                        cout << "The listenerName is empty." << endl;
                    } else {
                        cout << "Welcome, " + currentName << "!" << endl;
                        Listener newListener = Listener();
                        listeners[numListeners] = newListener;
                        listeners[numListeners].setListenerName(currentName);
                        numListeners++;
                    }
                    break;
                }
            case 6: {
                    string fileName;
                    cout << "Enter the listener info file name:" << endl;
                    cin >> fileName;
                    int readListener = readListenerInfo(fileName, listeners, numListeners, 100, 51);
                    numListeners += readListener;
                    if(readListener >= 100){
                        readListener = 100;
                        cout << "Total listeners in the database: " << readListener << endl;
                        cout << "Database is full. Some listeners may have not been added." << endl;
                        break;
                    }
                    if(readListener == -1){
                        cout << "Nothing saved to the database." << endl;
                    } else if (readListener == -2){
                        cout << "Database is already full. Nothing was added." << endl;
                    } else {
                        cout << "Total listeners in the database: " << readListener << endl;
                    }
                    break;
                }
            case 7: {
                    string name;
                    string song;
                    cout << "Enter a listener name:" << endl;
                    cin >> name;
                    cout << "Enter a song name:" << endl;
                    getline(cin >> ws, song);
                    int songIndex = -1;
                    int nameIndex = -1;
                    for(int i = 0; i < numListeners; i++){
                        if(listeners[i].getListenerName() == name){
                            nameIndex = i;
                        }
                    }
                    for(int i = 0; i < numSongs; i++){
                        if(songs[i].getTitle() == song){
                            songIndex = i;
                        }
                    }

                    if(songIndex == -1 && nameIndex == -1){
                        cout << name << " and " << song << " do not exist." << endl;
                    } else if(songIndex == -1){
                        cout << song << " does not exist." << endl;
                    } else if (nameIndex == -1){
                        cout << name << " does not exist." << endl;
                    } else {
                        int playCount = listeners[nameIndex].getPlayCountAt(songIndex);
                        cout << name << " has listened to " << song << " " << playCount << " times." << endl;
                    }
                    break;
                }
            case 8: {
                    string name;
                    cout << "Enter a listener name:" << endl;
                    cin >> name;
                    int stats = getListenerStats(name, listeners, numListeners, numSongs);
                    break;
                }
            case 9:
                cout << "Good bye!" << endl;
                break;
            default:
                cout << "Invalid input." << endl;
        }

    }
    return 0;
}