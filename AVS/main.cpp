/* main.cpp - исходный файл старта программы.
 * Сначала ввод типа фигуры, затем ввод типа цвета.
 * Следующей строкой ввод соответствующего количества точек, задающих фигуру на плоскости.
 */

// Домашнаяя работа Лосюкова Андрея (1 и 19 варианты).
#include <stdio.h>
#include <string.h>
#include "container.h"
#include "time.h"
#include "exceptions.h"

typedef struct container container;

int main(int argc, char* argv[]) {

    clock_t time_start = clock();

    // Обработка некорректного количества аргументов.
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;

    // Создание контейнера.
    Init(&c);

    if(!strcmp(argv[1], "-f")) {
        FILE *inputFile = fopen(argv[2], "a+");
        In(&c, inputFile);
    }
    else if(!strcmp(argv[1], "-n")) {
        long size =  strtol(argv[2], &argv[2], 0);
        if((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }


        srand(time(NULL));
        // Заполнение контейнера генератором случайных чисел.
        InRnd(&c, (int)size);
    }
    else {
        errMessage2();
        return 2;
    }


    // Открытие первого файла для записи.
    FILE *outputFile1;
    if(!(outputFile1 = fopen(argv[3], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод содержимого контейнера в файл
    fprintf(outputFile1, "Filled container:\n");
    Out(&c, outputFile1);
    fclose(outputFile1);

    // Открытие второго файла для записи.
    FILE *outputFile2;
    if(!(outputFile2 = fopen(argv[4], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод результатов выполнения дополнительной функции и содержимого измененного контейнера в файл.
    fprintf(outputFile2, "Square average = %f\n", SquareAverage(&c));
    fprintf(outputFile2, "Changed container:\n");
    RemoveAlternativesSmallSquare(&c);
    Out(&c, outputFile2);
    fclose(outputFile2);

    // Очистка контейнера.
    Clear(&c);

    printf("Stop\n");
    printf("Seconds: %f\n", ((double)(clock() - time_start)) / CLOCKS_PER_SEC);
    return 0;
}