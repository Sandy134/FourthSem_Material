import sys

d = {}


def add_entry():
    usn = input("Enter the usn of the student:")
    if usn not in d:
        print("Enter 3 subject marks:")
        marks = [int(i) for i in input().split(' ')]
        d[usn] = marks
    else:
        print("USN already exists")


def remove_entry():
    if len(d) == 0:
        print("Student Dictionary is empty!!")
        return
    usn = input("Enter the usn to remove:")
    try:
        print(f"Removed entry is {usn}:{d[usn]}")
        del d[usn]
    except KeyError as k:
        print("USN not present")


def display():
    if len(d) == 0:
        print("Student Dictionary is empty!!")
        return
    print("All the student details are:")
    # for key, value in d.items():
    #     print(key, ':', value, end='\t')
    #     print()
    print(d)


def compute():
    if len(d) == 0:
        print("Student Dictionary is empty!!")
        return
    usn = input("Enter the usn to compute:")
    try:
        a, b, c = d[usn]
        if a > b:
            if b > c:
                print(f"Avg is {(a + b) / 2}")
            else:
                print(f"Avg is {(a + c) / 2}")
        elif a > c:
            print(f"Avg is {(a + b) / 2}")
        else:
            print(f"Avg is {(b + c) / 2}")
    except KeyError as k:
        print("Usn not present!!")


while True:
    print("1)Add 2)Remove 3)Display 4)Compute 5)Exit")
    choice = int(input("Enter your choice:"))
    if choice == 1:
        add_entry()
    elif choice == 2:
        remove_entry()
    elif choice == 3:
        display()
    elif choice == 4:
        compute()
    else:
        sys.exit()
