#include "triangle.h"

/**
 * Ввод треугольника из файла
 * @param inputFile - входной поток.
 */
void Triangle::In(FILE *inputFile) {
    bool aX = Exceptions::GetInt(inputFile, &a.x);
    bool aY = Exceptions::GetInt(inputFile, &a.y);
    bool bX = Exceptions::GetInt(inputFile, &b.x);
    bool bY = Exceptions::GetInt(inputFile, &b.y);
    bool cX = Exceptions::GetInt(inputFile, &c.x);
    bool cY = Exceptions::GetInt(inputFile, &c.y);
    if (!aX || !aY || !bX || !bY || !cX || !cY) {
        printf("Некоторые значение были некорректными - теперь они ноль\n");
    }
}

/**
 * Случайная генерация треугольника.
 * Треугольник получится корректным.
 */
void Triangle::InRnd() {
    a.x = Random::next(0, 1000);
    a.y = Random::next(0, 1000);

    do {
        b.x = Random::next(0, 1000);
        b.y = Random::next(0, 1000);
    } while (a.x == b.x && a.y == b.y);

    do {
        c.x = Random::next(0, 1000);
        c.y = Random::next(0, 1000);
    } while (pow(a.x - b.x, 2) + pow(a.y - b.y, 2) >=
             pow(c.x - b.x, 2) + pow(c.y - b.y, 2) +
             pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
}

/**
 * Вывод информации о треугольнике в файл.
 * @param outputFile - файл.
 */
void Triangle::Out(FILE *outputFile) {
    fprintf(outputFile, "Треугольник:\n\t");
    fprintf(outputFile, "a = %d %d,\n\t", a.x, a.y);
    fprintf(outputFile, "b = %d %d,\n\t", b.x, b.y);
    fprintf(outputFile, "c = %d %d,\n\t", c.x, c.y);
    fprintf(outputFile, "Площадь = %f\n", Square());
    WriteColorInFile(outputFile);
}

/**
 * Вычисление площади треугольника.
 * @return площадь.
 */
// Вычисление площади треугольника.
double Triangle::Square() {
    return (double) (ceil(
            (1 / 2.0) * abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y))));
}