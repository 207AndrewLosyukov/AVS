from enum import Enum

# Перечислимый тип цветов фигуры.
class Colors(Enum):
    TRANSPARENT = 0
    RED = 1
    ORANGE = 2
    YELLOW = 3
    GREEN = 4
    LIGHTBLUE = 5
    BLUE = 6
    PURPLE = 7


# Класс фигуры.
class Shape:
    def __init__(self):
        self.color = Colors.TRANSPARENT

    # Установка цвет фигуры.
    def SetColor(self, i):
        self.color = i

    # Получение цвета фигуры.
    def GetColorString(self) -> str:
        if self.color == 1:
            return "RED"
        elif self.color == 2:
            return "ORANGE"
        elif self.color == 3:
            return "YELLOW"
        elif self.color == 4:
            return "GREEN"
        elif self.color == 5:
            return "LIGHTBLUE"
        elif self.color == 6:
            return "BLUE"
        elif self.color == 7:
            return "PURPLE"
        else:
            self.color = 0
            return "TRANSPARENT"

    # Создание фигуры.
    def Read(self, strArray, i):
        pass

    # Вывод данных о фигуре в консоль.
    def Print(self):
        pass

    # Вывод данных о фигуре в файл.
    def Write(self, ostream):
        pass

    # Вычисление площади фигуры.
    def Square(self):
        pass