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

    vector<Track> library;

    const string filename = "musicLibrary.dat";

    int choice;

    do {

        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {

        case 1:
            addTrack(library);
            break;

        case 2:
            displayLibrary(library);
            break;

        case 3:
            saveLibraryToFile(library, filename);
            break;

        case 4:
            loadLibraryFromFile(library, filename);
            break;

        case 5:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}