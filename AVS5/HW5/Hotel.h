#ifndef Hotel_class
#define Hotel_class

#include "mutex"
#include "Lady.h"
#include "Gentleman.h"
#include "thread"
#include "Room.h"

class Lady;
class Room;

/*
 * Отель.
 */
class Hotel {
    clock_t time_start;
    std::mutex mtx;
    int count_of_free_place = 40;
    /*
     * Массив комнат.
     */
    Room *rooms;

public:
    /*
     * Количество леди и джентельменов.
     */
    int count_of_ladies;
    int count_of_gentleman;

    Hotel(int count_of_ladies, int count_of_gentleman);

    /*
     * Попытка заезда для леди.
     */
    bool tryToMoveInLady();

    /*
     * Попытка заезда для джентельмена.
     */
    bool tryToMoveInGentleman();

    void start();
};


#endif
