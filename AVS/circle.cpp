#include "circle.h"


// Константное задание числа PI.
#define PI 3.141592

// Ввод параметров круга из файла.
void InCircle(struct circle *circle, FILE* inputFile) {
    bool centerX = GetInt(inputFile, &circle->center.x);
    bool centerY = GetInt(inputFile, &circle->center.y);
    bool radius = GetInt(inputFile, &circle->r );
    if (!centerX || !centerY || !radius) {
        printf("Some values was incorrect, they are zero now\n");
    }
}

// Рандомная генерация параметров круга.
void InRndCircle(struct circle *circle) {
    circle->center.x = Random();
    circle->center.y = Random();
    circle->r = Random();
}

// Вывод данных круга в файл.
void OutCircle(struct circle *circle, FILE* outputFile) {
    fprintf(outputFile, "Circle:\n\t");
    fprintf(outputFile, "x = %d,\n\t", circle->center.x);
    fprintf(outputFile, "y = %d,\n\t", circle->center.y);
    fprintf(outputFile, "r = %d,\n\t", circle->r);
    fprintf(outputFile, "Square = %f\n", SquareCircle(circle));
}

// Вычисление площади окружности.
double SquareCircle(struct circle *circle) {
    return PI * circle->r * circle->r;
}