#include "Gentleman.h"

Gentleman::Gentleman() = default;

Gentleman::Gentleman(Hotel *hotel) {
    this->hotel = hotel;
}

void Gentleman::start() {
    while (true) {
        this->hotel->tryToMoveInGentleman();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
