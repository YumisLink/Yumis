id = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

ns = [3, 6, 10, 3, 4, 5, 6, 8, 9, 10]
df = [500, 500, 500, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000]
T = 10

from random import randrange

ll = len(id)

for i in range(ll):
    with open("withered" + id[i] + '.in', "w") as f:
        print(ns[i], file=f)
        s = ""
        for _ in range(ns[i]):
            s += str(df[i] // 2 + randrange(df[i] // 2)) + " "
        print(s, file=f)