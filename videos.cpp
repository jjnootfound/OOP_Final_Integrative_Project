//including global libraries
#include <iostream>
using namespace std;

//include videos class
#include "videos.h"


//normal constructor for videos, without parameters
Videos::Videos() {
    id = "";
    name = "";
    length = 0;
    genre = "";
    rating = 0;
}

//ahora sí, parametrized constructor for the same class
Videos::Videos(string newId, string newName, int newLength, string newGenre, int newRating) {
    id = newId;
    name = newName;
    length = newLength;
    genre = newGenre;
    rating = newRating;

}

//declare setters
void Videos::setId(string newId) {
    id = newId;
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

//declare getters

//todo: declare this getters : id, name, genre, rating
string Videos::getId() {
    return id;
}
string Videos::getName() {
    return name;
}
string Videos::getGenre() {
    return genre;
}
int Videos::getRating() {
    return rating;
}
Videos::~Videos() {
}