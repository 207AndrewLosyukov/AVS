import math

from shape import *
from point import *


# Класс треугольника.
class Triangle(Shape):
    def __init__(self):
        self.a = Point()
        self.b = Point()
        self.c = Point()

    # Создание треугольника.
    def Read(self, strArray, i):
        self.a.x = int(strArray[i])
        self.a.y = int(strArray[i + 1])
        self.b.x = int(strArray[i + 2])
        self.b.y = int(strArray[i + 3])
        self.c.x = int(strArray[i + 4])
        self.c.y = int(strArray[i + 5])
        i += 6
        return i

    # Вывод данных о треугольнике в консоль.
    def Print(self):
        print(f"Triangle:\n"
              f"\tcolor - {self.GetColorString()}\n"
              f"\ta = {self.a.x} {self.a.y}\n"
              f"\tb = {self.b.x} {self.b.y}\n"
              f"\tc = {self.c.x} {self.c.y}\n"
              f"Square = {self.Square()}")

    # Вывод данных о треугольнике в файл.
    def Write(self, ostream):
        ostream.write(f"Triangle:\n"
                      f"\tcolor - {self.GetColorString()}\n"
                      f"\ta = {self.a.x} {self.a.y}\n"
                      f"\tb = {self.b.x} {self.b.y}\n"
                      f"\tc = {self.c.x} {self.c.y}\n"
                      f"Square = {self.Square()}")

    # Вычисление площади треугольника.
    def Square(self):
        return float(math.ceil(
            (1 / 2.0) * abs(self.a.x * (self.b.y - self.c.y) + 
            self.b.x * (self.c.y - self.a.y) + self.c.x * (self.a.y - self.b.y))))