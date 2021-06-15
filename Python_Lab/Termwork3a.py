import csv
import sys


class PriceException(Exception):
    pass


def readBooks(n, books):
    for i in range(n):
        book = [i for i in input('Enter book number,title,author and Price:').split(',')]
        book[0] = int(book[0])
        book[3] = float(book[3])
        books.append(book)

    with open('Books.csv', 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(books)


def searchAuthor():
    auth = input('Enter the author to search:')
    flag = 0
    with open("Books.csv", 'r', newline='') as f:
        r = csv.reader(f)
        for line in r:
            if auth == line[2]:
                flag = 1
                print(f'Book details are: {line}')
        if flag == 0:
            print('No Books with specified Author')


def searchPrice():
    price = float(input('Enter the price to search:'))
    flag = 0
    if price <= 0:
        raise PriceException('Price cannot be 0 or negative ')
        return
    with open("Books.csv", 'r', newline='') as f:
        r = csv.reader(f)
        for line in r:
            if price < float(line[3]):
                flag = 1
                print(f'Book details are: {line}')
        if flag == 0:
            print('No Books below the specified price price')


def searchTitle():
    word = input('Enter the author to search:')
    flag = 0
    with open("Books.csv", 'r', newline='') as f:
        r = csv.reader(f)
        for line in r:
            if word in line[1]:
                flag = 1
                print(f'Book details are: {line}')
        if flag == 0:
            print('No Books with specified word in title')


def main():
    books = []
    n = int(input('Enter the no of books:'))
    readBooks(n, books)
    while True:
        print('\n1)Search By Author\t2)Search Price\t3)Search Title\t4)Exit')
        choice = int(input('Enter your choice:'))
        if choice == 1:
            searchAuthor()
        elif choice == 2:
            try:
                searchPrice()
            except PriceException as pe:
                print(pe)
        elif choice == 3:
            searchTitle()
        elif choice == 4:
            sys.exit()
        else:
            print('Invalid choice,Plz ReEnter a Valid Option (1:4)!!')


if __name__ == '__main__':
    main()
