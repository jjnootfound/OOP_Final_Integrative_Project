#pragma once
#include <string>

class Videos {
protected:
    std::string ID;
    std::string name;
    int length; 
    std::string genre;
    int rating;

public:
    //constructors for videos, normal constructor and parametrized constructor
    Videos();

    Videos(std::string newID,
         std::string newName,
         int newLength,
         std::string newGenre,
         int newRating);
    
    //create setters and getters
    void setID(std::string newID);
    void setName(std::string newName);
    void setLength(int newLength);
    void setGenre(std::string newGenre);
    void setRating(int newRating);

    std::string getID();
    std::string getName();
    std::string getGenre();
    int getRating();
    
    virtual void showInfo() = 0; //abstract class

    virtual ~Videos() = 0;
    
};