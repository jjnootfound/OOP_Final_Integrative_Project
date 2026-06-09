//import global libraries 
#include <iostream>
using namespace std;

//import other classes
#include "videos.h"
#include "episode.h"
#include "movie.h"

//define csv files
#define SERIES_FILE "SeriesDta.csv"
#define MOVIES_FILE "MoviesData.csv"

void showMenu();

int main () {

    //declare pointers for each class
    Videos** videosArray = nullptr;
    Episode* episodesArray = nullptr;
    Movie* moviesArray = nullptr;

    //establishes datasize for episodes and movies :))
    int episodesSize = 0;
    int moviesSize = 0;
    bool dataLoaded = false;
    
    //variable to make the user choose an option in the menu
    int menuOption;

    //variable to store the sum of episode and movies sizes
    int summedSizes;

    episodesSize = countEpisodesDataLinesInCSV(SERIES_FILE);
    moviesSize = countMoviesDataLinesInCSV(MOVIES_FILE);

    //sum for the total sizes
    summedSizes = episodesSize + moviesSize;

    //menu for user to choose what to do in the program
    do {

        cout << endl;

        showMenu();

        cout << "Enter an option: ";
        cin>>menuOption;

        //switch case for the program to run depending on user's choice
        switch(menuOption){
            case 1:
            if(episodesSize == -1 && moviesSize == -1) {
                //detects error for dataset loading
                cerr << "Dataset could not be loaded from " << SERIES_FILE << "and " << MOVIES_FILE << "\n";
                return 1;
            } else {
                cout << "Dataset loaded" << endl;
            }

            //prints the status of series file: it has x entries
            cout <<"The file\"" << SERIES_FILE << "\" has: " << episodesSize << "entries\n";
            //allocating data in heap, it returns nullptr if not enough memory
            episodesArray = new(nothrow) Episode[episodesSize];

            cout <<"The file\"" << MOVIES_FILE << "\" has: " << moviesSize << "entries\n";
            moviesArray = new(nothrow) Movie[moviesSize];

            //error display in case nullptr is present
            if(episodesArray == nullptr || moviesArray == nullptr) {
                cerr << "There wasn't enough memory for the array\n";
                return 1;
            }
        
            //error handling and deleting the arrays to avoid memory leaks
            if(!loadEpisodesFromCSV(SERIES_FILE, episodesArray, episodesSize)) {
                cerr << "Error while loading dataset from " << SERIES_FILE << "\n";
                delete [] episodesArray;
                return 1;
            }
            if(!loadMoviesFromCSV(MOVIES_FILE, moviesArray, moviesSize)) {
                cerr << "error while loading dataset from " << MOVIES_FILE << "\n";
                delete [] moviesArray;
                return 1;
            }

            //if there's no error, data did load :))
            if(dataLoaded) {
                cout << "Data loaded successfully";
            }

            break;

            case 2:
            //case variables for rating and genre
            int rating;
            string genre;
            
            //variable to store the option for rating or genre
            int choose;

            //


            //make the user choose between genre and rating
            cout << "Select 1 for genre and 2 for rating" << endl;
            cin >> choose;

            break;
    } 
    while (menuOption != 0);
        return 0;
}

void showMenu(){

    cout<< "Menu: " << endl
        // options list
        << "Option 1: Load csv data files" << endl
        << "Option 2: Show the videos with a specific rating or from a specific genre." << endl
        << "Option 3: Show the episodes of a specific series with a specific rating." << endl
        << "Option 4: Show the movies with a specific rating." << endl
        << "Option 5: Rate a video" << endl
        << "Exit" << endl;
    
}