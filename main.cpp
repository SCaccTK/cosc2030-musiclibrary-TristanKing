#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Track {
    string title;
    string artist;
    string album;
    int duration;

    string genre;
    int year;
};

// FunFunctional
void addTrack(vector<Track>& library);
void displayLibrary(const vector<Track>& library);
void saveLibraryToFile(const vector<Track>& library, const string& filename);
void loadLibraryFromFile(vector<Track>& library, const string& filename);
void printMenu();

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}