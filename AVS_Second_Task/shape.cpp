#include "triangle.h"
#include "circle.h"
#include "rectangle.h"

/**
 * Вывод цвета в файл.
 * @param outFile - файл для вывода.
 */
void Shape::WriteColorInFile(FILE *outFile) {
    switch (color) {
        case RED:
            fprintf(outFile, "\tЦвет: Красный\n");
            break;
        case ORANGE:
            fprintf(outFile, "\tЦвет: Оранжевый\n");
            break;
        case YELLOW:
            fprintf(outFile, "\tЦвет: Желтый\n");
            break;
        case GREEN:
            fprintf(outFile, "\tЦвет: Зеленый\n");
            break;
        case LIGHTBLUE:
            fprintf(outFile, "\tЦвет: Голубой\n");
            break;
        case BLUE:
            fprintf(outFile, "\tЦвет: Синий\n");
            break;
        case PURPLE:
            fprintf(outFile, "\tЦвет: Фиолетовый\n");
            break;
    }
}

/**
 * Геттер для цвета.
 * @return цвет.
 */
Colors Shape::GetColor() {
    return color;
}

/**
 * Сеттер для цвета.
 * @param color - цвет.
 */
void Shape::SetColor(Colors newColor) {
    color = newColor;
}

/**
 * Статический ввод фигуры.
 * @param inputFile - входной файл.
 * @return экзмепляр фигуры.
 */
Shape *Shape::StaticIn(FILE *inputFile) {
    int k;
    bool check = Exceptions::GetInt(inputFile, &k);

    int colorType;
    bool checkColor = Exceptions::GetInt(inputFile, &colorType);
    if (!check || !checkColor)
        return nullptr;
    Shape *shape;
    switch (k) {
        case 1:
            shape = new Rectangle;
            break;
        case 2:
            shape = new Triangle;
            break;
        default:
            shape = new Circle;
            break;
    }
    shape->SetColor(Colors(colorType));
    shape->In(inputFile);
    return shape;
}

/**
 * Статический метод генерации рандомной фигуры.
 * @return фигура.
 */
Shape *Shape::StaticInRnd() {
    auto k = Random::next(1, 4);
    Shape *shape;
    switch (k) {
        case 1:
            shape = new Rectangle;
            break;
        case 2:
            shape = new Triangle;
            break;
        default:
            shape = new Circle;
            break;
    }
    shape->SetColor(Colors(Random::next(0, 7)));
    shape->InRnd();
    return shape;
}