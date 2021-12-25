#ifndef Gentleman_class
#define Gentleman_class

#include "Hotel.h"
#include "thread"
#include "chrono"

class Hotel;

class Gentleman {

public:
    Hotel *hotel;

    Gentleman();

    Gentleman(Hotel *hotel);

    void start();
};


#endif
