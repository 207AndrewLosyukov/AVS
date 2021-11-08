from shape import *
from point import *
import math

# Класс круга.
class Circle(Shape):
    def __init__(self):
        self.r = 0
        self.center = Point()

    # Создание круга по данным.
    def Read(self, strArray, i):
        self.center.x = int(strArray[i])
        self.center.y = int(strArray[i + 1])
        self.r = int(strArray[i + 2])
        i += 3
        return i

    # Вывод данных о круге.
    def Print(self):
        print(f"Circle:\n"
              f"\tcolor - {self.GetColorString()}\n"
              f"\tcenter = {self.center.x} {self.center.y}\n"
              f"\tr = {self.r}\n"
              f"Square = {self.Square()}")

    # Вывод данных о круге.
    def Write(self, ostream):
        ostream.write(f"Circle:\n"
                      f"\tcolor - {self.GetColorString()}\n"
                      f"\tcenter = {self.center.x} {self.center.y}\n"
                      f"\tr = {self.r}\n"
                      f"Square = {self.Square()}")

    # Вычисление площади круга.
    def Square(self):
        return float(math.pi * math.pow(self.r, 2))