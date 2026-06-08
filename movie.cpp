#include "movie.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Movie::Movie() : Videos(){
}

Movie::Movie(std::string newID, std::string newName, int newLength, std::string newGenre, int newRating) : 
Videos (newID, newName, newLength, newGenre, newRating){
}

void Movie::showInfo(){
    std::cout << "Movie: ID: " << ID << ", Name: " << name 
	<< ", Length: " << length << " minutes" << ", Genre: " << genre 
	<< " Rating: " << rating << std::endl;
}


bool loadMoviesFromCSV(std::string fileName, Movie* moviesArray, unsigned int arraySize) {
	std::ifstream		file(fileName);
	std::string			line;
	unsigned int	size = 0;

	if (!file.is_open()) {
		std::cerr << "Error opening the file: " << fileName << std::endl;
		return false;
	}

	// Skip header
	if(!getline(file, line)) {
		std::cerr << "The file has no header" << std::endl;
		file.close();
		return false;
	}

	std::cout << "Loading file: " << fileName << std::endl;

	while (getline(file, line)) {
		Movie			newMovie;
		std::stringstream	ss(line);
		std::string			cell;
		int 			campo = 0, errors = 0;

		while (getline(ss, cell, ',')) {
			if(!cell.length())
				errors++;

			switch(campo) {
				case 0:
					newMovie.setID(cell);
					break;
				case 1:
					newMovie.setName((cell));
					break;
				case 2:
					newMovie.setLength(stoi(cell));
					break;
				case 3:
					newMovie.setGenre(cell);
					break;
				default:
					errors++;
					break;
			}
			campo++;
		}

		if (errors || campo != MVS_ATTRIB_SIZE) {
			std::cerr << "Error at line:\n" << line << std::endl;
			file.close();
			return false;
		}

		if(size < arraySize) {
			moviesArray[size] = newMovie;
			size++;
		}
		else {
			std::cerr << "Error, the array is very small" << std::endl;
			file.close();
			return false;
		}
	}

	file.close();
	return true;
}


int countMoviesDataLinesInCSV(std::string fileName) {
    std::ifstream    file(fileName);
    int         lineCount = 0;
    std::string      line;

    // Count total amount of lines in the csv file
    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << fileName << std::endl;
        return -1;
    }

    // Skip header
    if(!getline(file, line)) {
        std::cerr << "The file has no header" << std::endl;
        file.close();
        return -1;
    }

    // Contar lines 
    while(getline(file, line)) {
        lineCount++;    
    }

    file.close();
    return(lineCount);
}
