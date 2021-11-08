import random
import sys
import math
from exceptions import*
from rectangle import*
from triangle import*
from circle import*

class GeneratorAndWriter:

    # Генерация массива рандомных фигур.
    @staticmethod
    def RndGenerateArr(count) -> list:
        arr = []
        for i in range(count):
            key = random.randint(1, 3)
            color = random.randint(1, 7)
            arr.append(key)
            arr.append(color)
            if key == 1:
                arr += GeneratorAndWriter.getRectangleCoords()
            elif key == 2:
                arr += GeneratorAndWriter.getTriangleCoords()
            elif key == 3:
                arr += GeneratorAndWriter.getCircleCoords()
        return [str(x) for x in arr]

    # Генерация рандомных точек для треугольника.
    @staticmethod
    def getTriangleCoords() -> list:
        x1 = random.randint(1, 1000)
        y1 = random.randint(1, 1000)
        x2 = random.randint(1, 1000)
        y2 = random.randint(1, 1000)
        x3 = random.randint(1, 1000)
        y3 = random.randint(1, 1000)

        while x1 == x2 and y1 == y2:
            x2 = random.randint(1, 1000)
            y2 = random.randint(1, 1000)
        while (math.pow(x1 - x2, 2) + math.pow(y1 - y2, 2) >=
               math.pow(x3 - x2, 2) + math.pow(y3 - y2, 2) +
               math.pow(x1 - x3, 2) + math.pow(y1 - y3, 2)):
            x3 = random.randint(1, 1000)
            y3 = random.randint(1, 1000)
        return [x1, y1, x2, y2, x3, y3]

    # Генерация рандомных точек для прямоугольника.
    @staticmethod
    def getRectangleCoords() -> list:
        x1 = random.randint(1, 999)
        y1 = random.randint(2, 1000)
        x2 = random.randint(1, 1000)
        y2 = random.randint(1, 1000)

        while x2 <= x1 or y2 >= y1:
            x2 = random.randint(1, 1000)
            y2 = random.randint(1, 1000)
        return [x1, y1, x2, y2]

    # Генерация рандомных точек для круга.
    @staticmethod
    def getCircleCoords() -> list:
        r = random.randint(1, 1000)
        x = random.randint(1, 1000)
        y = random.randint(1, 1000)
        return [r, x, y]

    # Метод, который проверяет на возможность дальнейшего считывания.
    # Вывод ошибки при некорректных данных.
    @staticmethod
    def ConinueOrExit(start_index, count_of_offset, array):
        if start_index + count_of_offset > len(array):
            Exceptions.incorrectFileInput()
            sys.exit()
        for i in range(count_of_offset):
            if not array[start_index + i].isdigit():
                Exceptions.incorrectFileInput()
                sys.exit()
    
    #  Статический метод считывания.
    @staticmethod
    def Read(container, strArray) -> bool:
        array_len = len(strArray)
        # Индекс, задающий текущую строку в массиве.
        i = 0
        while i < array_len:
            GeneratorAndWriter.ConinueOrExit(i, 2, strArray)

            # Получение типа фигуры.
            key = int(strArray[i])
            # Получение цвета фигуры.
            color = int(strArray[i + 1])
            i += 2
            if key == 1:
                GeneratorAndWriter.ConinueOrExit(i, 4, strArray)
                shape = Rectangle()
                # Получение прямоугольника.
                i = shape.Read(strArray, i)
            elif key == 2:
                GeneratorAndWriter.ConinueOrExit(i, 6, strArray)
                shape = Triangle()
                # Получение треугольника.
                i = shape.Read(strArray, i)
            elif key == 3:
                GeneratorAndWriter.ConinueOrExit(i, 3, strArray)
                shape = Circle()
                # Получение круга.
                i = shape.Read(strArray, i)
            else:
                # Если что-то пошло не так, вывод сообщения и выход из функции.
                print("Something wrong. Error!")
                return False
            shape.SetColor(color)
            container.arr.append(shape)
        return True

    # Генерация рандомного теста с заданным количеством фигур
    # и запись полученного массива в файл.
    @staticmethod
    def WriteTest(count):
        str_arr = GeneratorAndWriter.RndGenerateArr(count)
        file = open("random_input.txt", 'w')
        i = 0
        while i < len(str_arr):
            key = int(str_arr[i])
            color = int(str_arr[i + 1])
            i += 2
            file.write(f"{key} {color}\n")
            if key == 1:
                file.write(f"{str_arr[i]} {str_arr[i + 1]} {str_arr[i + 2]} {str_arr[i + 3]}\n")
                i += 4
            elif key == 2:
                file.write(f"{str_arr[i]} {str_arr[i + 1]} {str_arr[i + 2]} "
                           f"{str_arr[i + 3]} {str_arr[i + 4]} {str_arr[i + 5]}\n")
                i += 6
            elif key == 3:
                file.write(f"{str_arr[i]} {str_arr[i + 1]} {str_arr[i + 2]}\n")
                i += 3
        file.close()