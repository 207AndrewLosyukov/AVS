#ifndef __container__
#define __container__

#include <stdio.h>
#include "shape.h"
#include "container.h"
#include "stdlib.h"

typedef struct shape shape;

struct container {
    // Максимальная длина.
    enum {max_len = 10000};
    // Текущая длина.
    int len;
    // Массив фигур (содержимое контейнера).
    shape *cont[max_len];
};

// Инициализация контейнера.
void Init(struct container *c);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(struct container *c);

// Ввод содержимого контейнера из указанного потока.
void In(struct container *c, FILE* inputFile);

// Рандомная генерация содержимого контейнера.
void InRnd(struct container *c, int size);

// Вывод содержимого контейнера в указанный поток.
void Out(struct container *c, FILE* outputFile);

// Вычисление среднего значения площадей всех фигур в контейнере.
double SquareAverage(struct container *c);

// Вывод содержимого контейнера в указанный поток.
void RemoveAlternativesSmallSquare(struct container *c);

#endif