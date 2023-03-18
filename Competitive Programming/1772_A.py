def solve(problem):
    list1 = []
    list2 = []
    for x in range(0, len(problem), 1):
        if problem[x] != "+":
            list1.append(problem[x])
        else:
            break

    if problem[x] == "+":
        for y in range(x+1, len(problem), 1):
            list2.append(problem[y])

        num1 = 0
        num2 = 0
        n = 0

        for z in range(len(list1)-1, -1, -1):
            num1 = num1 + (int(list1[z])*pow(10, n))
            n += 1

        n = 0

        for w in rang(len(list2)-1, -1, -1):
            num2 = num2 + (int(list2[w])*pow(10, n))
            n += 1

        return (num1 + num2)


t = int(input())
while (t > 0):
    t = t-1
    x = input()
    print(solve(x))
