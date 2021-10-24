#ifndef __triangle__
#define __triangle__

#include <stdio.h>
#include <math.h>
#include "random.h"
#include "point.h"
#include <stdbool.h>
#include "exceptions.h"
#include "shape.h"

/**
 * Класс треугольника (наследуется от Shape)
 */
class Triangle : public Shape {
public:

    /**
     * Ввод треугольника из файла
     * @param inputFile - входной поток.
     */
    virtual void In(FILE *inputFile);

    /**
     * Случайная генерация треугольника.
     * Треугольник получится корректным.
     */
    virtual void InRnd();

    /**
     * Вывод информации о треугольнике в файл.
     * @param outputFile - файл.
     */
    virtual void Out(FILE *outputFile);

    /**
     * Вычисление площади треугольника.
     * @return площадь.
     */
    virtual double Square();

    /**
    * Деструктор.
    */
    virtual ~Triangle() {}

private:
    // Крайние точки треугольника.
    Point a, b, c;
};

#endif