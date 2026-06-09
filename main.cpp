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
    Videos* videosArray = nullptr;
    Episode* episodesArray = nullptr;
    Movie* moviesArray = nullptr;

    //establishes datasize for episodes and movies :))
    int episodesSize = 0;
    int moviesSize = 0;

    //variable to make the user choose an option in the menu
    int menuOption;

    episodesSize = countEpisodesDataLinesInCSV(SERIES_FILE);
    moviesSize = countMoviesDataLinesInCSV(MOVIES_FILE);

    //menu for user to choose what to do in the program
    do {

        cout << endl;

        showMenu();

        cout << "Enter an option: ";
        cin>>menuOption;

        //switch case for the program to run depending on user's choice
        switch(menuOption){
            case 1:
            //load finles
            break;
            case 2:
            //Show all the data
            break;

        }
    } 
    while (menuOption != 0);
        return 0;
}

void showMenu(){

    cout<< "Menu: " << endl
        // options list
        << "Option 1: Load csv data files" << endl
        << "Option 2: Show all the data" << endl
        << "Option 3: Show videos with an specific rating or  specific genre" << endl
        << "Option 4: Show episodes of a specific series with a specific rating" << endl
        << "Option 5: Show movies with a specific rating" << endl
        << "Option 6: Rate a video" << endl
        << "Option 0: Exit menu" << endl;

}