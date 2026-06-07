#pragma once
#include "videos.h"
#define MVS_ATTRIB_SIZE 4

class Movie : public Videos{

    public:
        Movie();
        Movie(std::string newID, std::string newName, int newLength, std::string newGenre, int newRating);
        void showInfo() override;
        
};

bool loadMoviesFromCSV(std::string fileName, Movie* moviesArray, unsigned int arraySize);
int countMoviesDataLinesInCSV(std::string fileName);
