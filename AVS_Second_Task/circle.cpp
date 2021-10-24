#include "circle.h"

// Константное задание числа PI.
#define PI 3.1415926

/**
 * Ввод параметров круга из файла
 * @param inputFile - входной поток.
 */
void Circle::In(FILE *inputFile) {
    bool centerX = Exceptions::GetInt(inputFile, &center.x);
    bool centerY = Exceptions::GetInt(inputFile, &center.y);
    bool radiusBool = Exceptions::GetInt(inputFile, &radius);
    if (!centerX || !centerY || !radiusBool) {
        printf("Некоторые значение были некорректными - теперь они ноль\n");
    }
}

/**
 * Случайна генерация круга.
 * При этом гарантируется, что круг корректен.
 */
void Circle::InRnd() {
    center.x = Random::next(0, 1000);
    center.y = Random::next(0, 1000);
    radius = Random::next(0, 100);
}

/**
 * Вывод информации о круге в файл.
 * @param outputFile - файл.
 */
void Circle::Out(FILE *outputFile) {
    fprintf(outputFile, "Круг:\n\t");
    fprintf(outputFile, "x = %d,\n\t", center.x);
    fprintf(outputFile, "y = %d,\n\t", center.y);
    fprintf(outputFile, "r = %d,\n\t", radius);
    fprintf(outputFile, "Площадь = %f\n", Square());
    WriteColorInFile(outputFile);
}

// Вычисление площади окружности.
double Circle::Square() {
    return PI * radius * radius;
}