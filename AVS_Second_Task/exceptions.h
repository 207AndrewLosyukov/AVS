// exceptions.h - содержит класс программных ошибок,
// которые могут возникать во время работы программы, и их обработку.

#ifndef __exceptions__
#define __exceptions__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Класс программных ошибок.
 * Содержит основные методы для вывод информации об ошибка и их обработки.
 */
class Exceptions {
public:

    /**
    * Метод осууществляет попытку считывания числа из файла.
    * Если возможно - считывает.
    * @param inputFile - файл.
    * @param number - переменная, в которую нужно записать значение.
    * @return (не-)успех считывания.
    */
    static bool GetInt(FILE *inputFile, int *number);

    /**
    * Вывод сообщения об ошибке 1 - неккоректное количество аргументов.
    */
    static void errMessage1();

    /**
    * Вывод сообщения об ошибке 2 - неккоректный ключ.
    */
    static void errMessage2();

};

#endif