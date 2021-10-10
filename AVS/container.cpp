// Контейнер (19 вариант).
#include "container.h"

// Инициализация контейнера.
void Init(struct container *c) {
    c->len = 0;
}

// Очистка контейнера от элементов (освобождение памяти).
void Clear(struct container *c) {
    for (int i = 0; i < (*c).len; i++) {
        free(c->cont[i]);
    }
    c->len = 0;
}

// Ввод содержимого контейнера из указанного потока.
void In(struct container *c, FILE *inputFile) {
    while ((c->cont[c->len] = InShape(inputFile)) != NULL) {
        c->len++;
    }
    fclose(inputFile);
}

// Рандомная генерация содержимого контейнера.
void InRnd(struct container *c, int size) {
    while (c->len < size) {
        if ((c->cont[c->len] = InRndShape()) != 0) {
            c->len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток.
void Out(struct container *c, FILE *outputFile) {
    fprintf(outputFile, "Container contains ");
    fprintf(outputFile, "%d", c->len);
    fprintf(outputFile, " elements.\n");
    for (int i = 0; i < c->len; i++) {
        fprintf(outputFile, "%d", i + 1);
        fprintf(outputFile, ": ");
        OutShape(c->cont[i], outputFile);
    }
}

// Вычисление средней площади всех фигур в контейнере.
double SquareAverage(struct container *c) {
    double sum = 0.0;
    for (int i = 0; i < c->len; i++) {
        sum += SquareShape(c->cont[i]);
    }
    return sum / c->len;
}

// Удаление из контейнера всех фигур, площадь которых больше среднего.
void RemoveAlternativesSmallSquare(struct container *c) {
    double average = SquareAverage(c);
    for (int i = 0; i < c->len; i++) {
        if (SquareShape(c->cont[i]) < average) {
            c->len--;
            for (int j = i; j < c->len; j++) {
                c->cont[j] = c->cont[j + 1];
            }
            c->cont[c->len] = NULL;
            i--;
        }
    }
}