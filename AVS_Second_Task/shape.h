#ifndef __shape__
#define __shape__

#include <stdio.h>
#include "random.h"
#include <stdbool.h>

/**
 * Перечисление цветов.
 */
enum Colors {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    LIGHTBLUE,
    BLUE,
    PURPLE
};

/**
 * Абстрактный класс фигуры.
 * Содержит спецификацию любой фигуры.
 */
class Shape {
    /**
     * Общее для всех алтернатив свйоство - цвет.
     */
    Colors color;
public:

    /**
    * Статический ввод фигуры.
    * @param inputFile - входной файл.
    * @return экзмепляр фигуры.
    */
    static Shape *StaticIn(FILE *inputFile);

    /**
     * Метод ввода параметров из файла.
     * @param inputFile - входной поток.
     */
    virtual void In(FILE *inputFile) = 0;

    /**
    * Статический метод генерации рандомной фигуры.
    * @return фигура.
    */
    static Shape *StaticInRnd();

    /**
     * Метод рандомной генерации.
     */
    virtual void InRnd() = 0;

    /**
     * Метод вывода информации в файл.
     * @param outputFile - файл.
     */
    virtual void Out(FILE *inputFile) = 0;

    /**
     * Вычисление площади фигуры.
     * @return площадь.
     */
    virtual double Square() = 0;

    /**
    * Геттер для цвета.
    * @return цвет.
    */
    Colors GetColor();

    /**
    * Сеттер для цвета.
    * @param color - цвет.
    */
    void SetColor(Colors color);

    /**
    * Вывод цвета в файл.
    * @param outFile - файл для вывода.
    */
    void WriteColorInFile(FILE *outFile);

    /**
     * Деструктор.
     */
    virtual ~Shape() = default;
};

#endif