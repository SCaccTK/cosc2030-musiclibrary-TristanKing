# heads up i could not figure out how to put screenshots in here so i linked them in the actual GitHub file in the file RESULTS.


## HOW DOES MY CODE WORK?
the program is a simple music library that allows the you to add, display, save, and load music tracks. The program uses a track structure to store information about each song, the library is stored in a vector so that multiple tracks can be added.
- **Title** - The name of the song
- **Artist** - The artist who performed the song
- **Album** - The album the song is from
- **Duration** - The length of the song in seconds
- **Genre** - The type of music
- **Year** - The release year

### Saving and Loading
The program uses binary file input and output to save the music library. When you select **Save Library**, the program writes the number of tracks and the information for each track to musicLibrary.dat. When you select **Load Library**, the program reads the saved information from the file and places the tracks back into the library. The **.dat** file is a binary file, so its contents may appear as unreadable characters if opened in a text editor. so it needs to be accessed through the program using the **Save and Load** options.

its like a worse Spotify!!
