#include <iostream>
#include "Hotel.h"
#include "mutex"
#include "Room.h"

bool Hotel::tryToMoveInGentleman() {
    mtx.lock();
    if (Hotel::count_of_free_place > 0) {
        if (count_of_gentleman > 0) {
            int r = rand() % 25;
            if (rooms[r].isForGentleman && rooms[r].addPeopleForRoom()) {
                std::cout << "Джентельмен заселился в комнату под номером: " << r+1 << " Seconds: "
                          << ((double) (clock() - time_start)) / CLOCKS_PER_SEC << '\n';
                count_of_gentleman--;
                count_of_free_place--;
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mtx.unlock();
}

bool Hotel::tryToMoveInLady() {
    mtx.lock();
    if (Hotel::count_of_free_place > 0) {
        if (count_of_ladies > 0) {
            int r = rand() % 25;
            if (!rooms[r].isForGentleman && rooms[r].addPeopleForRoom()) {
                std::cout << "Дама заселилась в комнату под номером: " << r+1 << " Seconds: "
                          << ((double) (clock() - time_start)) / CLOCKS_PER_SEC << '\n';
                count_of_ladies--;
                count_of_free_place--;
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mtx.unlock();
}

void Hotel::start() {
    for (int i = 0; i < count_of_ladies; i++) {
        Lady lady(this);
        std::thread t(&Lady::start, lady);
        t.detach();
    }

    for (int i = 0; i < count_of_gentleman; i++) {
        Gentleman gentleman(this);
        std::thread t(&Gentleman::start, gentleman);
        t.detach();
    }

    while ((this->count_of_ladies > 0 || this->count_of_gentleman > 0) && count_of_free_place > 0 &&
    ((double) (clock() - time_start)) / CLOCKS_PER_SEC < 1.5) {
    }
}

Hotel::Hotel(int count_of_ladies, int count_of_gentleman) {
    rooms = new Room[25];
    this->count_of_ladies = count_of_ladies;
    this->count_of_gentleman = count_of_gentleman;
    for (int i = 0; i < 10; ++i) {
        if (count_of_ladies > 0) {
            rooms[i] = Room(true, false);
            count_of_ladies--;
        } else {
            if (count_of_gentleman > 0) {
                rooms[i] = Room(true, true);
                count_of_gentleman--;
            } else {
                rooms[i] = Room(true, rand() % 2 == 0);
            }
        }
    }
    for (int i = 10; i < 25; ++i) {
        if (count_of_ladies > 0) {
            rooms[i] = Room(false, false);
            count_of_ladies-=2;
        } else {
            if (count_of_gentleman > 0) {
                rooms[i] = Room(false, true);
                count_of_gentleman-=2;
            } else {
                rooms[i] = Room(false, rand() % 2 == 0);
            }
        }
    }
    time_start = clock();
    Hotel::mtx.unlock();
}
