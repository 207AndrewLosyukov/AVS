/* Исходный файл, содержащий в себе процедуры
 * обработки обобщенной фигуры и создания специфических.
 * */

#include "shape.h"

typedef struct shape shape;

// Отдельная процедура установки цвета обобщенной фигуры.
void SetColor(struct shape *shape, int colorType) {
    switch (colorType) {
        case 1:
            shape->col = shape::color::RED;
            break;
        case 2:
            shape->col = shape::color::ORANGE;
            break;
        case 3:
            shape->col = shape::color::YELLOW;
            break;
        case 4:
            shape->col = shape::color::GREEN;
            break;
        case 5:
            shape->col = shape::color::LIGHTBLUE;
            break;
        case 6:
            shape->col = shape::color::BLUE;
            break;
        case 7:
            shape->col = shape::color::PURPLE;
            break;
        default:
            shape->col = shape::color::TRANSPARENT;
            break;
    }
}

// Вывод информации о цвете обобщенной фигуры в файл.
void OutColor(struct shape *shape, FILE* outFile) {
    switch (shape->col) {
        case shape::color::RED:
            fprintf(outFile, "\tColor: RED\n");
            break;
        case shape::color::ORANGE:
            fprintf(outFile, "\tColor: ORANGE\n");
            break;
        case shape::color::YELLOW:
            fprintf(outFile, "\tColor: YELLOW\n");
            break;
        case shape::color::GREEN:
            fprintf(outFile, "\tColor: GREEN\n");
            break;
        case shape::color::LIGHTBLUE:
            fprintf(outFile, "\tColor: LIGHTBLUE\n");
            break;
        case shape::color::BLUE:
            fprintf(outFile, "\tColor: BLUE\n");
            break;
        case shape::color::PURPLE:
            fprintf(outFile, "\tColor: PURPLE\n");
            break;
        default:
            fprintf(outFile, "\tColor: TRANSPARENT\n");
            break;
    }
}

// Ввод параметров обобщенной фигуры из файла.
shape* InShape(FILE* inputFile) {

    shape *sp;
    int k;
    bool checkType = GetInt(inputFile, &k);
    sp = (shape*)malloc(sizeof(shape));

    int colorType;
    bool checkColor = GetInt(inputFile, &colorType);
    if (!checkType || !checkColor)
        return NULL;
    SetColor(sp, colorType);

    switch(k) {
        case 1:
            sp->k = shape::key::RECTANGLE;
            InRectangle(&(sp->r), inputFile);
            return sp;
        case 2:
            sp->k = shape::key::TRIANGLE;
            InTriangle(&(sp->t), inputFile);
            return sp;
        case 3:
            sp->k = shape::key::CIRCLE;
            InCircle(&(sp->c), inputFile);
            return sp;
        default:
            return 0;
    }
}

// Рандомная генерация некой фигуры.
shape *InRndShape() {
    shape *sp;
    int colorType = Random() % 7 + 1;
    sp = (shape*)malloc(sizeof(shape));
    SetColor(sp, colorType);
    int k = Random() % 3 + 1;
    switch(k) {
        case 1:
            sp->k = shape::key::RECTANGLE;
            InRndRectangle(&(sp->r));
            return sp;
        case 2:
            sp->k = shape::key::TRIANGLE;
            InRndTriangle(&(sp->t));
            return sp;
        case 3:
            sp->k = shape::key::CIRCLE;
            InRndCircle(&(sp->c));
            return sp;
        default:
            return 0;
    }
}

// Вывод информации о данной фигуре в файл.
void OutShape(struct shape *s, FILE* outputFile) {
    switch(s->k) {
        case shape::key::RECTANGLE:
            OutRectangle(&(s->r), outputFile);
            OutColor(s, outputFile);
            break;
        case shape::key::TRIANGLE:
            OutTriangle(&(s->t), outputFile);
            OutColor(s, outputFile);
            break;
        case shape::key::CIRCLE:
            OutCircle(&(s->c), outputFile);
            OutColor(s, outputFile);
            break;
        default:
            fprintf(outputFile, "Incorrect figure!\n");
    }
}

// Вычисление периметра фигуры.
double SquareShape(struct shape *s) {
    switch(s->k) {
        case shape::key::RECTANGLE:
            return SquareRectangle(&(s->r));
        case shape::key::TRIANGLE:
            return SquareTriangle(&(s->t));
        case shape::key::CIRCLE:
            return SquareCircle(&(s->c));
        default:
            return 0.0;
    }
}