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
void addTrack(vector<Track>& library) {

    Track newTrack;

    cout << "\nEnter track title: ";
    getline(cin, newTrack.title);

    cout << "Enter artist: ";
    getline(cin, newTrack.artist);

    cout << "Enter album: ";
    getline(cin, newTrack.album);

    cout << "Enter duration in seconds: ";
    cin >> newTrack.duration;
    cin.ignore();

    cout << "Enter genre: ";
    getline(cin, newTrack.genre);

    cout << "Enter release year: ";
    cin >> newTrack.year;
    cin.ignore();

    library.push_back(newTrack);

    cout << "Track added!" << endl;
}

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

void printMenu() {

    cout << "\n===== MUSIC LIBRARY =====" << endl;
    cout << "1. Add Track" << endl;
    cout << "2. Display Library" << endl;
    cout << "3. Save Library" << endl;
    cout << "4. Load Library" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayLibrary(const vector<Track>& library) {

    if (library.empty()) {
        cout << "\nThe library is empty." << endl;
        return;
    }

    cout << "\n===== MUSIC LIBRARY =====" << endl;

    for (int i = 0; i < library.size(); i++) {

        cout << "\nTrack #" << i + 1 << endl;
        cout << "Title: " << library[i].title << endl;
        cout << "Artist: " << library[i].artist << endl;
        cout << "Album: " << library[i].album << endl;
        cout << "Duration: " << library[i].duration << " seconds" << endl;
        cout << "Genre: " << library[i].genre << endl;
        cout << "Year: " << library[i].year << endl;
    }
}
// saving system for library!!
void saveLibraryToFile(const vector<Track>& library, const string& filename) {

    ofstream outFile(filename, ios::binary);

    if (!outFile) {
        cout << "Error opening file." << endl;
        return;
    }

    // num of tracks
    size_t numberOfTracks = library.size();

    outFile.write(reinterpret_cast<const char*>(&numberOfTracks),
                  sizeof(numberOfTracks));

    // track
    for (const Track& track : library) {

        // title
        size_t length = track.title.size();
        outFile.write(reinterpret_cast<const char*>(&length),
                      sizeof(length));
        outFile.write(track.title.c_str(), length);

        // artist
        length = track.artist.size();
        outFile.write(reinterpret_cast<const char*>(&length),
                      sizeof(length));
        outFile.write(track.artist.c_str(), length);

        // album
        length = track.album.size();
        outFile.write(reinterpret_cast<const char*>(&length),
                      sizeof(length));
        outFile.write(track.album.c_str(), length);

        // length
        outFile.write(reinterpret_cast<const char*>(&track.duration),
                      sizeof(track.duration));

        // type of music
        length = track.genre.size();
        outFile.write(reinterpret_cast<const char*>(&length),
                      sizeof(length));
        outFile.write(track.genre.c_str(), length);

        // year
        outFile.write(reinterpret_cast<const char*>(&track.year),
                      sizeof(track.year));
    }

    outFile.close();

    cout << "\nLibrary saved successfully!" << endl;
}