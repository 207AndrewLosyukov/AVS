#ifndef __container__
#define __container__

#include <stdio.h>
#include "shape.h"
#include "stdlib.h"

/**
 * Класс контейнера.
 * Хранит в себе массив ссылок на обобщенные фигуры.
 */
class Container {
public:
    /**
     * Конструктор класса.
     */
    Container();

    /**
     * Деструктор класса.
     */
    ~Container();

    /**
     * Ввод коллекции фигур из файла.
     * @param inputFile - файл.
     */
    void In(FILE *inputFile);

    /**
     * Рандомная генерация содержимого контейнера
     * @param size -  количество элементов, которые необходимо сгенерировать.
     */
    void InRnd(int size);

    /**
     * Вывод содержимого контейнера в файл.
     * @param outputFile - файл.
     */
    void Out(FILE *outputFile);


    /**
     * Удаление всех фигур, площадь которых меньше среднего.
     */
    void RemoveAlternativesSmallSquare();

    /**
     * Получение средней площади фигур.
     * @return средняя площадь.
     */
    double SquareAverage();

private:

    // Длина.
    int length;

    // Массив ссылок на фигуры.
    Shape *shapes[10001];
};

#endif