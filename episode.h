#pragma once
#include <string>
#include "videos.h"
#define EPSD_ATTRIB_SIZE 6

class Episode : public Videos {

    private:
        std::string episodeTitle;
        int season;

    public:
        Episode();
        Episode(std::string newID, std::string newName, int newLength, std::string newGenre, int newRating, std::string newEpisodeTitle, int newSeason);
        void setTitle(std::string newEpisodeTitle);
        void setSeason(int newSeason);
        std::string getTitle();
        int getSeason();
        void showInfo() override;

};

bool loadEpisodesFromCSV(std::string fileName, Episode* partsArray, unsigned int arraySize);
int countEpisodesDataLinesInCSV(std::string fileName);
