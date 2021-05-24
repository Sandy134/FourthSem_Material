import sys


def highest(d):
    course_name = ""
    high = 0
    for walk in d.values():
        if walk[2] > high:
            high = walk[2]
            course_name = walk[0]

    return course_name, high


def display(d):
    if len(d) == 0:
        print('Dictionary is empty!!')
        return
    course_code = input('Enter the course code')
    try:
        details = d[course_code]
        print(f'Details related to the course code {course_code} are:')
        print(f'Course name :{details[0]}')
        print(f'Faculty name :{details[1]}')
        print(f'Number of Registrations :{details[2]}')
    except KeyError as v:
        print('Sorry no course code found in the dictionary')


def add_entry(d):
    course_code = input('Enter the course code:')
    course_details = []
    print('Enter the course name, faculty name and no of registrations:')
    course_details.append(input())
    course_details.append(input())
    course_details.append(int(input()))
    d[course_code] = course_details


def main():
    d = {}
    while True:
        print("\n1)Add 2)Highest Registrations 3)Display 4)Exit ")
        choice = int(input('Enter your choice:'))
        if choice == 1:
            add_entry(d)
        elif choice == 2:
            course_name, no = highest(d)
            print(f'{course_name} has highest registrations of {no}')
        elif choice == 3:
            display(d)
        elif choice == 4:
            sys.exit()
        else:
            print('Invalid choice please Reenter')


if __name__ == '__main__':
    main()
