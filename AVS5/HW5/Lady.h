#ifndef Lady_class
#define Lady_class

#include "Hotel.h"
#include "thread"
#include "chrono"
#include "random"

class Hotel;

class Lady {

public:
    Hotel *hotel;

    Lady();

    Lady(Hotel *hotel);

    void start();
};


#endif
