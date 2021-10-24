#ifndef __generationTests__
#define __generationTests__

#include <cstdio>
#include "string.h"
#include "random.h"
#include "math.h"
#include "container.h"

/**
 * Класс генератора тестов.
 */
class generationTests {
private:
    /**
     * Генерация рандомных координат точек для прямоугольника.
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     */
    static void generateRectangleCoordinates(int &x1, int &y1, int &x2, int &y2);

    /**
     * Генерация рандомных координат точек для треугольника.
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @param x3
     * @param y3
     */
    static void generateTriangleCoordinates(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3);

    /**
     * Генерация рандомных координат точек для круга.
     * @param x
     * @param y
     * @param r - радиус.
     */
    static void generateCircleCoordinates(int &x, int &y, int &r);

public:
    /**
     * Генерация рандомного теста с заданным количеством фигур и запись в файл.
     * @param size - количество фигур.
     */
    static void generateTest(int size);
};


#endif