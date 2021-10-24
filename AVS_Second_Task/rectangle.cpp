#include "rectangle.h"

/**
 * Ввод прямоугольника из файла
 * @param inputFile - входной поток.
 */
void Rectangle::In(FILE *inputFile) {
    bool p1X = Exceptions::GetInt(inputFile, &point1.x);
    bool p1Y = Exceptions::GetInt(inputFile, &point1.y);
    bool p2X = Exceptions::GetInt(inputFile, &point2.x);
    bool p2Y = Exceptions::GetInt(inputFile, &point2.y);
    if (!p1X || !p1Y || !p2X || !p2Y) {
        printf("Некоторые значение были некорректными - теперь они ноль\n");
    }
}

/**
 * Случайная генерация прямоугольника.
 * Прямоугольник - корректен.
 */
void Rectangle::InRnd() {
    do {
        point1.x = Random::next(0, 1000);
        point1.y = Random::next(0, 1000);
    } while (point1.x == 999 || point1.y == 0);

    do {
        point2.x = Random::next(0, 1000);
        point2.y = Random::next(0, 1000);
    } while (point2.x <= point1.x || point2.y >= point1.y);
}

/**
 * Вывод информации о прямоугольнике в файл.
 * @param outputFile - файл, в который нужно вывести информацию.
 */
void Rectangle::Out(FILE *outputFile) {
    fprintf(outputFile, "Прямоугольник:\n\t");
    fprintf(outputFile, "Первая точка: %d %d\n\t", point1.x, point1.y);
    fprintf(outputFile, "Вторая точка: %d %d\n\t", point2.x, point2.y);
    fprintf(outputFile, "Площадь = %f\n", Square());
    WriteColorInFile(outputFile);
}

/**
 * Вычисление площади прямоугольника.
 * @return площадь.
 */
// Вычисление площади прямоугольника.
double Rectangle::Square() {
    return abs(point2.x - point1.x) * abs(point2.y - point1.y);
}