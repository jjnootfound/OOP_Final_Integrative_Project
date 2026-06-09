#pragma once

#include <string>
using namespace std;

class Videos {
protected:
    string ID;
    string name;
    int length; 
    string genre;
    int rating;

public:
    //constructors for videos, normal constructor and parametrized constructor
    Videos();

    Videos(string newID,
         string newName,
         int newLength,
         string newGenre,
         int newRating);
    
    //create setters and getters
    void setID(string newID);
    void setName(string newName);
    void setLength(int newLength);
    void setGenre(string newGenre);
    void setRating(int newRating);

    string getId();
    string getName();
    string getGenre();
    int getRating();

    virtual void showInfo() = 0; //abstract class

    virtual ~Videos();

};