#include "Lady.h"

Lady::Lady() = default;

Lady::Lady(Hotel *hotel) {
    this->hotel = hotel;
}

void Lady::start() {
    while (true) {
        this->hotel->tryToMoveInLady();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
