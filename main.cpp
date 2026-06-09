//import global libraries 
#include <iostream>
using namespace std;

//import other classes
#include "videos.h"
#include "episode.h"
#include "movie.h"

//define csv files
#define SERIES_FILE "SeriesData.csv"
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

    do {
        //method to show the menu to the user
        cout << endl;
        showMenu();

        //make the user choose an option
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

            //here we will store the summed array
            videosArray = new(nothrow) Videos *[summedSizes];

            //handle error if videos array was not created
            if(!videosArray) {
                cerr << "array was not created \n";
                delete [] episodesArray;
                delete [] moviesArray;
                return 1;
            }

            //copy each position of the episodes and movies array
            //directly to the heap where videos array is
            int reference = 0;
            for (int i = 0; i < episodesSize; i++) {
                videosArray[reference] = &episodesArray[i];
                reference++;
            }

            for (int i = 0; i < moviesSize; i++) {
                videosArray[reference] = &moviesArray[i];
                reference++;
            }

            break;

            case 2: {
                //case variables for rating and genre
                int rating;
                string genre;
                
                //variable to store the option for rating or genre
                int choose;

            
                //make the user choose between genre and rating
                cout << "Select 1 for genre and 2 for rating" << endl;
                cin >> choose;

                if(choose == 1) {
                    cout << "Select a video genre: " << endl;
                    cin >> genre;

                    //iterates in a for the videos array to get
                    //the pointer uses the actual memory value and gets genre
                    for(int i = 0; i < summedSizes; i++) {
                        if(videosArray[i] -> getGenre() == genre) {
                            videosArray[i]-> showInfo();
                        }
                    }
                    //same case but for rating
                } else if (choose == 2) {
                    cout << "Type a rating from one to five " << endl;
                    cin >> rating;

                    for(int i = 0; i < summedSizes; i++) {
                        if(videosArray[i] -> getRating() == rating) {
                            videosArray[i] -> showInfo();
                        }
                    }
                }
            }

            break;

            case 3: {
                string wantedSeries;
                int wantedRating;

                cout << "Type here the series name:";
                cin >> wantedSeries;

                cout << "Type the rating from 1 to 5";
                cin >> wantedRating;

                //todo: finish case 4
            }
            break;

            case 4:

            break;

            case 5: {
                //local variables
                int rating;
                string titleToRate;

                cout << "Type the tile you want to rate";
                cin.ignore(); //cleans whatever was stored there
                getline(cin, titleToRate); //gets the whole line and stores it in variable

                for(int i = 0; i < summedSizes; i++) {
                    if (videosArray[i] -> getName() == titleToRate) {
                        videosArray[i] -> showInfo();

                        do {
                            cout << "Rate the video from 1 to 5";
                            cin >> rating;

                            //validate new rating is within the allowed ranges
                            if (rating < 1 || rating > 5) {
                                cout <<"Invalid rating" << endl;
                            }
                        } while (rating < 1 || rating > 5);

                        //update the rating with the setter
                        videosArray[i] -> setRating(rating);
                    }
                }
            }
            
            break;
        } 
    
    } while (menuOption != 0);
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
        << "Exit (type 0)" << endl;
    
}