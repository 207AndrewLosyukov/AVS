#include "exceptions.h"

/**
 * Метод осууществляет попытку считывания числа из файла.
 * Если возможно - считывает.
 * @param inputFile - файл.
 * @param number - переменная, в которую нужно записать значение.
 * @return (не-)успех считывания.
 */
bool Exceptions::GetInt(FILE *inputFile, int *number) {
    int count = fscanf(inputFile, "%d", number);
    if (count == EOF || count == 0) {
        number = 0;
        return false;
    }
    return true;
}


/**
 * Вывод сообщения об ошибке 1 - неккоректное количество аргументов.
 */
void Exceptions::errMessage1() {
    printf("Некорректное количество аргументов!\n");
}

/**
 * Вывод сообщения об ошибке 2 - неккоректный ключ.
 */
void Exceptions::errMessage2() {
    printf("Некорректный ключ!\n");
}
