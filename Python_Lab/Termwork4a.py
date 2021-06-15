import sys


class Person:
    def __init__(self, f, n, e):
        self.__fullname = f
        self.__lastname = n
        self.__email = e

    def getPerson(self):
        return self.__fullname + ' ' + self.__lastname


class Customer(Person):
    def __init__(self, f, l, e, id):
        Person.__init__(self, f, l, e)
        self.__ID = id

    def getID(self):
        return self.__ID


class Employee(Person):
    def __init__(self, f, l, e, pan):
        Person.__init__(self, f, l, e)
        self.__PAN = pan

    def getPan(self):
        return self.__PAN


def show(obj):
    if isinstance(obj, Customer):
        print("Customer:", obj.getPerson(), obj.getID())
    elif isinstance(obj, Employee):
        print("Employee:", obj.getPerson(), obj.getPan())


def main():
    while True:
        n = int(input('\n1)Customer\t2)Employee\t3)Exit:'))
        if n == 1:
            fname, lname, email, id = input('Enter the Fname, lname, email and id of the Customer:').split(' ')
            c = Customer(fname, lname, email, id)
            show(c)

        elif n == 2:
            fname, lname, email, pan = input('Enter the Fname, lname, email and Pan of the Employee:').split(' ')
            e = Employee(fname, lname, email, pan)
            show(e)

        elif n == 3:
            sys.exit()
        else:
            print('Invalid choice!Plz Reenter')


if __name__ == '__main__':
    main()
