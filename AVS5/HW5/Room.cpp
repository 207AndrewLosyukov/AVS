#include "Room.h"

Room::Room() = default;

Room::Room(bool isForOnePerson, bool isForGentleman) {
    this->isForOnePerson = isForOnePerson;
    this->isForGentleman = isForGentleman;
    if (isForOnePerson) {
        countFreeInRoom = 1;
    } else {
        countFreeInRoom = 2;
    }
    if (isForGentleman) {
        gentleman = new Gentleman[countFreeInRoom];
    } else {
        ladies = new Lady[countFreeInRoom];
    }
}

bool Room::addPeopleForRoom() {
    if (isForGentleman) {
        if (isForOnePerson) {
            if (countFreeInRoom == 1) {
                countFreeInRoom--;
                gentleman[0] = Gentleman();
                return true;
            } else {
                return false;
            }
        } else {
            if (countFreeInRoom == 2) {
                countFreeInRoom--;
                gentleman[0] = Gentleman();
                return true;
            } else if (countFreeInRoom == 1) {
                countFreeInRoom--;
                gentleman[1] = Gentleman();
                return true;
            } else {
                return false;
            }
        }
    } else {
        if (isForOnePerson) {
            if (countFreeInRoom == 1) {
                countFreeInRoom--;
                ladies[0] = Lady();
                return true;
            } else {
                return false;
            }
        } else {
            if (countFreeInRoom == 2) {
                countFreeInRoom--;
                ladies[0] = Lady();
                return true;
            } else if (countFreeInRoom == 1) {
                countFreeInRoom--;
                ladies[1] = Lady();
                return true;
            } else {
                return false;
            }
        }
    }
}
