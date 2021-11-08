# Класс ошибок.
class Exceptions:

    # Обработка некорректных аргументов.
    @staticmethod
    def incorrectArguments():
        print("Incorrect arguments!\n"
              "Normal format:\n"
              "\t-f input.txt output.txt\n"
              "\t-n count_shapes output.txt\n"
              "\t-g count_random_digit")

    # Проверка числа на попадание в промежуток.
    @staticmethod
    def incorrectCount(count) -> bool:
        if count > 10000 or count < 0:
            print(f"incorrect number of figures = {count}. Set 0 < number <= 10000")
            return True
        return False

    # Во входном файле присутсвуте неккоректный формат.
    # Например, вместо числа введеная строка или для фигуры нет достаточного количества аргументов.
    @staticmethod
    def incorrectFileInput():
        print("Program closed with exception - Incorrect file!\n"
              "Try again")