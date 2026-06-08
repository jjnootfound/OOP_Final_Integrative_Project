//including global libraries
#include <iostream>
using namespace std;

//include videos class
#include "videos.h"


//normal constructor for videos, without parameters
Videos::Videos() {
    ID = "";
    name = "";
    length = 0;
    genre = "";
    rating = 0;
}

//ahora sí, parametrized constructor for the same class
Videos::Videos(string newID, string newName, int newLength, string newGenre, int newRating) {
    ID = newID;
    name = newName;
    length = newLength;
    genre = newGenre;
    rating = newRating;

}

//declare setters
void Videos::setID(string newId) {
    ID = newId;
}
void Videos::setName(string newName) {
    name = newName;
}
void Videos::setLength(int newLength) {
    length = newLength;
}
void Videos::setGenre(string newGenre) {
    genre = newGenre;
}
void Videos::setRating(int newRating) {
    rating = newRating;
}

Videos::~Videos() {
}