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
