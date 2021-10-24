#ifndef __rectangle__
#define __rectangle__

#include <stdio.h>
#include "random.h"
#include "point.h"
#include <stdbool.h>
#include "exceptions.h"
#include "shape.h"

/**
 * Класс прямоугольника (наследуется от Shape)
 */
class Rectangle : public Shape {
public:

    /**
     * Ввод прямоугольника из файла
     * @param inputFile - файл.
     */
    virtual void In(FILE *outputFile);

    /**
     * Случайная генерация прямоугольника.
     */
    virtual void InRnd();

    /**
     * Вывод информации о прямоугольнике в файл.
     * @param outputFile - файл.
     */
    virtual void Out(FILE *outputFile);

    /**
     * Вычисление площади прямоугольника.
     * @return площадь.
     */
    virtual double Square();

    /**
    * Деструктор.
    */
    virtual ~Rectangle() {}

private:
    Point point1, point2;
};

#endif