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

int main () {

    //declare pointers for each class
    Videos* videosArray = nullptr;
    Episode* episodesArray = nullptr;
    Movie* moviesArray = nullptr;

    //establishes datasize for episodes and movies :))
    int episodesSize = 0;
    int moviesSize = 0;

    //variable to make the user choose an option in the menu
    int menuOptions;

    episodesSize = countEpisodesDataLinesInCSV(SERIES_FILE);
    moviesSize = countMoviesDataLinesInCSV(MOVIES_FILE);

    //menu for user to choose what to do in the program
    do {
        cout<< "Media Menu: choose an option below (1-x)\n";
        // options list
        cout << "Option 1: Load csv files\n";
        cout <<"Option 2: Show videos with a specific rating or from a specific genre\n";
        cout <<"Option 3: Show episodes of a specific series with a specific rating\n";
        cout <<"Option 4: Show movies with a specific rating\n";
        cout <<"Option 5: Rate a video\n";
        cout <<"Option 6: Exit menu \n";

        cin>>menuOptions;
    } 
    while (menuOptions == 6);
        return 0;