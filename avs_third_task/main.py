import os.path
import sys
from container import*
from exceptions import*
from generatorAndWriter import*

def BaseLogic():
    print('start')

    container = Container()
    # Проверка на корректность считывания фигур из массива.
    is_correct = GeneratorAndWriter.Read(container, strArray)
    if not is_correct:
        print('end')
        sys.exit()

    # Вывод контейнера до функции контейнера в консоль.
    print("Before container function")
    print("-----------------")
    container.Print()
    print(f"Average square: {container.SquareAverage()}")
    print("-----------------")

    ofile = open(outputFileName, 'w')

    # Вывод контейнера до функции контейнера в файл.
    ofile.write("\tBefore container function\n")
    ofile.write("-----------------\n")
    container.Write(ofile)
    ofile.write(f"Average square: {container.SquareAverage()}\n")
    ofile.write("-----------------\n")

    # Удаление всех фигур, площади которых меньше средней площади.
    container.RemoveAlternativesSmallSquares()

    # Выводсодержимом контейнера после функции контейнера в консоль.
    print("\nAfter container function")
    print("-----------------")
    container.Print()
    print("-----------------")

    # Вывод контейнера после функции контейнера в файл.
    ofile.write("\nAfter container function\n")
    ofile.write("-----------------")
    container.Write(ofile)
    ofile.write("-----------------")
    ofile.close()

    print('end')


# Здесь происходит валидация введенных аргументов и загрузка данных из файл в массив.
if __name__ == '__main__':
    if len(sys.argv) < 2 or len(sys.argv) > 4:
        Exceptions.incorrectArguments()
        sys.exit(1)
    if sys.argv[1] == "-f":
        if len(sys.argv) == 4:
            inputFileName = sys.argv[2]
            outputFileName = sys.argv[3]
        elif len(sys.argv) == 3:
            inputFileName = sys.argv[2]
            outputFileName = "output.txt"
        else:
            inputFileName = "No file"

        # Чтение файла, с данными, разделенными пробелами и переводами строки.
        if not os.path.isfile(inputFileName):
            print(f"File '{inputFileName}' not found")
            sys.exit(1)
        ifile = open(inputFileName)
        str = ifile.read()
        ifile.close()

        # Формирование массива строк, содержащего данные в виде массива строк.
        strArray = [x for x in str.replace("\n", " ").split(" ") if x != ""]
        BaseLogic()
    elif sys.argv[1] == "-n":
        count = -1
        if len(sys.argv) < 3 or not sys.argv[2].isdigit():
            Exceptions.incorrectArguments()
            sys.exit(1)
        if len(sys.argv) == 4:
            count = int(sys.argv[2])
            outputFileName = sys.argv[3]
        elif len(sys.argv) == 3:
            count = int(sys.argv[2])
            outputFileName = "output.txt"
        if not Exceptions.incorrectCount(count):
            strArray = GeneratorAndWriter.RndGenerateArr(count)
            BaseLogic()
    elif sys.argv[1] == "-g":
        if len(sys.argv) < 3 or not sys.argv[2].isdigit():
            Exceptions.incorrectArguments()
            sys.exit(1)
        count = int(sys.argv[2])
        # Запуск генератора, если введенно корректное количество фигур.
        if not Exceptions.incorrectCount(count):
            GeneratorAndWriter.WriteTest(count)
            print("Generated!")
    else:
        Exceptions.incorrectArguments()