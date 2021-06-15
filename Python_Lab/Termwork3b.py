import sys


class EmptyDataException(Exception):
    pass


def readFile():
    with open('input.txt') as f:
        data = f.read()
        if len(data) == 0:
            raise EmptyDataException('File is empty(No data in input file)')
            return
        return data


def writeFile(data):
    with open('output.txt', 'w') as f:
        f.write(data[::-1])


def main():
    try:
        data = readFile()
    except EmptyDataException as ede:
        print(ede)
        sys.exit()
    writeFile(data)


if __name__ == '__main__':
    main()
