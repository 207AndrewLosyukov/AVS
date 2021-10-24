#include "container.h"

/**
 * Конструктор класса.
 */
Container::Container() {
    length = 0;
}

/**
 * Ввод фигур из файла.
 * @param inputFile - файл.
 */
void Container::In(FILE *inputFile) {
    while ((shapes[length] = Shape::StaticIn(inputFile)) != nullptr) {
        length++;
    }
    fclose(inputFile);
}

/**
 * Рандомная генерация содержимого контейнера.
 * @param size - количество элементов, которые необходимо сгенерировать.
 */
void Container::InRnd(int size) {
    while (length < size) {
        if ((shapes[length] = Shape::StaticInRnd()) != nullptr) {
            length++;
        }
    }
}

/**
* Вывод содержимого контейнера в файл.
* @param outputFile - файл.
*/
void Container::Out(FILE *outputFile) {
    fprintf(outputFile, "Контейнер содержит ");
    fprintf(outputFile, "%d", length);
    fprintf(outputFile, " элементов.\n");
    for (int i = 0; i < length; i++) {
        fprintf(outputFile, "%d", i + 1);
        fprintf(outputFile, ": ");
        shapes[i]->Out(outputFile);
    }
}

/**
 * Вычиление средней площади всех фигур.
 * @return средняя площадь.
 */
// Вычисление средней площади всех фигур в контейнере.
double Container::SquareAverage() {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += shapes[i]->Square();
    }
    return sum / length;
}

 /**
 * Удаление из контейнера всех фигур, площадь которых меньше среднего.
 */
void Container::RemoveAlternativesSmallSquare() {
    double average = SquareAverage();
    for (int i = 0; i < length; i++) {
        if (shapes[i]->Square() < average) {
            length--;
            for (int j = i; j < length; j++) {
                shapes[j] = shapes[j + 1];
            }
            shapes[length] = nullptr;
            i--;
        }
    }
}

/**
 * Деструктор контейнера.
 */
Container::~Container() {
    for (int i = 0; i < length; i++) {
        delete shapes[i];
        shapes[i] = nullptr;
    }
    length = 0;
}