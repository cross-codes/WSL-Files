import copy
strength = []
max = 0


def create_list(lst, element):
    lst.append(element)


def display(lst):
    temp_lst = copy.deepcopy(lst)
    temp_lst.sort()
    max = temp_lst[len(lst) - 1]
    second_max = temp_lst[len(lst) - 2]
    for x in range(0, len(lst) - 1, 1):
        if lst[x] == max:
            print(str(int(lst[x]) - int(second_max)) + "", end=" ")
        else:
            print(str(int(lst[x]) - int(max)) + "", end=" ")
    x = len(lst) - 1
    if lst[x] == max:
        print(str(int(lst[x]) - int(second_max)) + "")
    else:
        print(str(int(lst[x]) - int(max)) + "")


a = int(input())
d = int(input())
while (a > 0):
    b = input()
    if len(b) > 1:
        a -= 1
        c = b.split()
        for y in range(0, len(c), 1):
            create_list(strength, c[y])
        display(strength)
        strength = []
