#11/5/2021

MAX = 3
    
def add(q, item):
    if len(q) == MAX:
        print("\nQueue Overflow")
    else:
        q.append(item)
def delete(q):
    if len(q) == 0:
        return '#'
    else:
        return q.pop(0)
    
def disp(q):
    if len(q) == 0:
        print("\nQueue is empty")
        return
    else:
        print("\nQueue Contents are :",q)
    
def main():
    queue = []
    while True:
        print("\n1.add   2.Remove    3.Display    4.Exit")
        opt = int(input("Enter your option : "))
        if opt == 1:
            item = input("Enter the item to be added to the queue : ")
            add(queue, item)
        elif opt == 2:
            item = delete(queue)
            if item == '#':
                print("\nQueue Underflow")
            else:
                print("\nItem Deleted")
        elif opt == 3:
            disp(queue)
        elif opt == 4:
            break
        else:
            print("\nPlease enter a valid option ")
    
if __name__=='__main__':
    main()
 
    