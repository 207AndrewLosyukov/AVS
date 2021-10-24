#ifndef __circle__
#define __circle__

#include <stdio.h>
#include "random.h"
#include "point.h"
#include "exceptions.h"
#include "shape.h"
#include <stdbool.h>

/**
 * Класс круга (наследуется от Shape)
 */
class Circle : public Shape {
public:

    /**
     * Ввод параметров круга из файла
     * @param inputFile - входной поток.
     */
    virtual void In(FILE *inputFile);

    /**
     * Случайная генерация круга.
     * При этом гарантируется, что круг корректен.
     */
    virtual void InRnd();

    /**
     * Вывод информации о круге в файл.
     * @param outputFile - файл.
     */
    virtual void Out(FILE *outputFile);

    /**
     * Вычисление площади круга.
     * @return площадь.
     */
    virtual double Square();

    /**
    * Деструктор.
    */
    virtual ~Circle() {}

private:
    // Точка центра круга.
    Point center;
    // Числовое значение радиуса круга.
    int radius;
};

#endif