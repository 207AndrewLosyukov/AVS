#include <cstring>
#include "container.h"
#include <ctime>
#include "exceptions.h"
#include "generationTests.h"

/**
 * Мейн.
 * @param argc число переданных оргументов.
 * @param argv массив аргументов.
 * @return код завершения программы.
 */
int main(int argc, char *argv[]) {
    if (argc == 3 && !strcmp(argv[1], "-g")) {
        int size = strtol(argv[2], &argv[2], 0);
        if ((size < 1) || (size > 10000)) {
            printf("Некорректное число фигур = %d. Введите число > 0 и <= 10000\n", size);
            return 4;
        }
        generationTests::generateTest(size);
        printf("Тесты успешно сгенерированы!\n");
        return 5;
    }

    clock_t time_start = clock();

    // Обработка некорректного количества аргументов.
    if (argc != 5) {
        Exceptions::errMessage1();
        return 1;
    }

    printf("Старт\n");
    Container c;


    if (!strcmp(argv[1], "-f")) {
        FILE *inputFile = fopen(argv[2], "r");
        if (inputFile == nullptr) {
            printf("Некорректный входной файл");
            return 6;
        }
        c.In(inputFile);
    } else if (!strcmp(argv[1], "-n")) {
        int size = strtol(argv[2], &argv[2], 0);
        if ((size < 1) || (size > 10000)) {
            printf("Некорректное число фигур = %d. Введите число > 0 и <= 10000\n", size);
            return 3;
        }


        srand(time(nullptr));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    } else {
        Exceptions::errMessage2();
        return 2;
    }


    // Открытие первого файла для записи.
    FILE *outputFile1;
    if (!(outputFile1 = fopen(argv[3], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод содержимого контейнера в файл
    fprintf(outputFile1, "Заполненный контейнер:\n");
    c.Out(outputFile1);
    fclose(outputFile1);

    // Открытие второго файла для записи.
    FILE *outputFile2;
    if (!(outputFile2 = fopen(argv[4], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод результатов выполнения дополнительной функции и содержимого измененного контейнера в файл.
    fprintf(outputFile2, "Средняя площадь = %f\n", c.SquareAverage());
    fprintf(outputFile2, "Измененный контейнер:\n");
    c.RemoveAlternativesSmallSquare();
    c.Out(outputFile2);
    fclose(outputFile2);

    printf("\nКоличество секунд: %f\n", ((double) (clock() - time_start)) / CLOCKS_PER_SEC);
    return 0;
}