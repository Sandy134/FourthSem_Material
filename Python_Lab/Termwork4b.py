from math import *
import sys


class Polygon:
    def __init__(self, n):
        self.n = n  # taking number of sides of the polygon
        self.sides = [0] * n  # initialising sides to zero

    def readSides(self):
        print(f'Enter the value of {self.n} sides:')
        for i in range(0, len(self.sides)):
            self.sides[i] = int(input(f'Enter the side {i + 1}:'))

    def displaySides(self):
        print('Sides of the polygon are:')
        print(self.sides)


class Triangle(Polygon):
    def __init__(self, n):
        super().__init__(n)

    def computeArea(self):
        a, b, c = self.sides
        s = (a + b + c) / 2
        area = sqrt(s * (s - a) * (s - b) * (s - c))
        return round(area, 2)


class Rectangle(Polygon):
    def __init__(self, n):
        super().__init__(n)

    def computeArea(self):
        a, b, c, d = self.sides
        return round(a * b, 2)


def main():
    while True:
        print('\n1)Triangle 2)Rectangle 3)Exit')
        choice = int(input('Enter your choice:'))
        if choice == 1:
            flag = 1
            t = Triangle(3)
            t.readSides()
            a, b, c = t.sides
            if a >= b + c or b >= a + c or c >= a + b:
                print('Triangle cannot be formed')
                flag = 0
            if flag != 0:
                t.displaySides()
                print(f'Area of Triangle is {t.computeArea()}')

        elif choice == 2:
            flag = 1
            r = Rectangle(4)
            r.readSides()
            a, b, c, d = r.sides
            if a != c or b != d:
                print('Rectangle cannot be formed!')
                flag = 0
            if flag != 0:
                r.displaySides()
                print(f'Area of Rectangle is {r.computeArea()}')
        elif choice == 3:
            sys.exit(0)
        else:
            print('Invalid choice! Plz Reenter..')


if __name__ == '__main__':
    main()
