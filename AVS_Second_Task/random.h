#ifndef __random__
#define __random__

#include <stdlib.h>
#include "stdint.h"

/**
 * Класс рандомизации.
 */
class Random {
public:
    /**
     * Получить следующее рандомное число.
     * @return рандомное число.
     */
    static int next(int left = 0, int right = INT32_MAX);
};

#endif