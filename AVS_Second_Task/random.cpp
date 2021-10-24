#include "random.h"

/**
 * Получить следующее рандомное число.
 * @return рандомное число.
 */
int Random::next(int left, int right) {
    if (left < right) {
        return rand() % (right - left) + left;
    }
    return 0;
}