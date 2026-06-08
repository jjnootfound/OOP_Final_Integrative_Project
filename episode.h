#pragma once
#include <string>
#include "video.h"
#define EPSD_ATTRIB_SIZE 6

class Episode : public Video {

    private:
        std::string episodeTitle;
        int season;

    public:
        Episode();
        Episode(std::string newID, std::string newName, int newLength, std::string newGenre, int newRating, std::string newEpisodeTitle, int newSeason);
        void setTitle(std::string newEpisodeTitle);
        std::string getTitle();
        void setSeason(int newSeason);
        int getSeason();
        void showInfo() override;

};

bool loadEpisodesFromCSV(std::string fileName, Episode* partsArray, unsigned int arraySize);
int countEpisodesDataLinesInCSV(std::string fileName);
