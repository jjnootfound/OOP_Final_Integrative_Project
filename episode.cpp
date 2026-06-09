#include "episode.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Episode::Episode() : Videos(){
}

Episode::Episode(std::string newID, std::string newName, int newLength, std::string newGenre, int newRating, std::string newEpisodeTitle, int newSeason) : 
Videos(newID, newName, newLength, newGenre, newRating), episodeTitle(newEpisodeTitle), season(newSeason) {
}

void Episode::setTitle(std::string newEpisodeTitle){
    episodeTitle = newEpisodeTitle;
}

std::string Episode::getTitle(){
    return episodeTitle;
}

void Episode::setSeason(int newSeason){
    season = newSeason;
}

int Episode::getSeason(){
    return season;
}

void Episode::showInfo(){
    std::cout << "Episode: ID: " << ID << ", Name: " << name 
    << ", Length: " << length << " minutes" << ", Genre: " << genre 
    << ", Rating: " << rating << ", Title: " << episodeTitle << "Season: " << season << std::endl;
}

bool loadMoviesFromCSV(std::string fileName, Episode* episodesArray, unsigned int arraySize) {
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
		Episode			newEpisode;
		std::stringstream	ss(line);
		std::string			cell;
		int 			columnIndex = 0, errors = 0;

		while (getline(ss, cell, ',')) {
			if(!cell.length())
				errors++;

			switch(columnIndex) {
				case 0:
					newEpisode.setID(cell);
					break;
				case 1:
					newEpisode.setName(cell);
					break;
				case 2:
					newEpisode.setLength(stoi(cell));
					break;
				case 3:
					newEpisode.setGenre(cell);
					break;
                case 4:
                    newEpisode.setTitle(cell);
                    break;
                case 5:
                    newEpisode.setSeason(stoi(cell));
                    break;
				default:
					errors++;
					break;
			}
			columnIndex++;
		}

		if (errors || columnIndex != EPSD_ATTRIB_SIZE) {
			std::cerr << "Error at line:\n" << line << std::endl;
			file.close();
			return false;
		}

		if(size < arraySize) {
			episodesArray[size] = newEpisode;
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
