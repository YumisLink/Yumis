id = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

ns = [30, 50, 100, 2000, 4000, 6000, 10000, 10000, 30000, 30000]
ms = [300, 300, 300, 50000, 50000, 50000, 50000, 50000, 50000, 50000]
ds = [10, 30, 50, 1000, 500, 200, 100, 10, 5, 1]

T = 10

from random import randrange

ll = len(id)

for i in range(ll):
    with open("leylines" + id[i] + '.in', "w") as f:
        print(ns[i], ms[i], file=f)
        ws = [0] * ds[i]
        for j in range(ds[i]):
            ws[j] = randrange(50000)
        for j in range(1, ns[i]):
            print(j + 1, randrange(j) + 1, ws[randrange(ds[i])], file=f)
        for j in range(ms[i] - ns[i] + 1):
            print(randrange(ns[i]) + 1, randrange(ns[i]) + 1, ws[randrange(ds[i])], file=f)