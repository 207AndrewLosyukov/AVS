#include <iostream>
#include <ctime>
#include <cstring>
#include "Hotel.h"
#include "thread"
#include "time.h"

void incorrectCountOfArgumentsError() {
    std::cout << "Некорректное число аргументов" << "\n";
}

void incorrectFirstArgumentError() {
    std::cout << "Некорректный первый аргумент" << "\n";
}

void incorrectTypeOfArgumentsError() {
    std::cout << "Некорректный тип аргументов" << "\n";
}

void incorrectCountOfManError() {
    std::cout << "Некорректное количество людей данного пола" << "\n";
}

int main(int argc, char *argv[]) {
    clock_t time_start = clock();
    srand(time(NULL));
    int count_of_ladies, count_of_gentleman;
    if (argc < 2) {
        incorrectCountOfArgumentsError();
        exit(1);
    }
    if (strcmp(argv[1], "-r") != 0 && strcmp(argv[1], "-f") != 0) {
        incorrectFirstArgumentError();
        exit(1);
    }
    if (strcmp(argv[1], "-r") == 0) {
        if (argc != 2) {
            incorrectCountOfArgumentsError();
            exit(1);
        }
        count_of_ladies = rand() % 50 + 1;
        count_of_gentleman = rand() % 50 + 1;
    } else {
        if (argc != 4) {
            incorrectCountOfArgumentsError();
            exit(1);
        }
        try {
            count_of_ladies = std::stoi(argv[2]);
        }
        catch (std::invalid_argument e) {
            incorrectTypeOfArgumentsError();
            exit(1);
        }
        if (count_of_ladies < 0 || count_of_ladies > 100) {
            incorrectCountOfManError();
            exit(1);
        }
        try {
            count_of_gentleman = std::stoi(argv[3]);
        }
        catch (std::invalid_argument e) {
            incorrectTypeOfArgumentsError();
            exit(1);
        }
        if (count_of_gentleman < 0 || count_of_gentleman > 100) {
            incorrectCountOfManError();
            exit(1);
        }
    }

    std::cout << "Количество леди: " << count_of_ladies << '\n';
    std::cout << "Количество джентельменов: " << count_of_gentleman << '\n';
    auto *hotel = new Hotel(count_of_ladies, count_of_gentleman);

    hotel->start();
    std::cout << "\n";
    std::cout << count_of_gentleman - hotel->count_of_gentleman << " - джентельменов заселилось" << "\n";
    std::cout << count_of_ladies - hotel->count_of_ladies << " - дам заселилось" << "\n";
    std::cout << "\n";
    std::cout << hotel->count_of_gentleman << " - джентельменов разбили палатку под окнами дам" << "\n";
    std::cout << hotel->count_of_ladies << " - дам решило выбрать другой отель" << "\n";
    std::cout << "Seconds: " << ((double) (clock() - time_start)) / CLOCKS_PER_SEC;
    return 0;
}
