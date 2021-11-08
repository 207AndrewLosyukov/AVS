# Класс контейнера
class Container:
    def __init__(self):
        self.arr = []

    # Вывод контейнера в консоль.
    def Print(self):
        print("Container consist of {} shapes:\n".format(len(self.arr)))
        for shape in self.arr:
            shape.Print()

    # Вывод контейнера в файл.
    def Write(self, ostream):
        ostream.write("Container consist of {} shapes:\n".format(len(self.arr)))
        for shape in self.arr:
            shape.Write(ostream)
            ostream.write("\n")

    # Вычисление средней площади фигур.
    def SquareAverage(self) -> float:
        square = 0.0
        for shape in self.arr:
            square += shape.Square()
        return square / (len(self.arr) if len(self.arr) != 0 else 1)

    # Удаление всех фигур, площадь которых меньше средней.
    def RemoveAlternativesSmallSquares(self):
        average = self.SquareAverage()
        index = 0
        for i in range(len(self.arr)):
            if self.arr[index].Square() < average:
                self.arr.remove(self.arr[index])
                index -= 1
            index += 1