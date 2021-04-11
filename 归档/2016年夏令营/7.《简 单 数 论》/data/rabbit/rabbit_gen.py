maxk = 90000000
# id = ['0', '1', '2', '3', '4', '5', '6', '7']
id = ['8', '9', '10',
      '11', '12', '13', '14', '15', '16', '17', '18', '19']
ns = [100, 100, 100, 100, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
ms = ns
from random import randrange

ll = len(id)

for i in range(ll):
    with open("rabbit" + id[i] + '.in', "w") as f:
        print(ns[i], ms[i], file=f)
        for _ in range(ms[i]):
            x = randrange(1, ns[i])
            y = randrange(1, ns[i])
            if x > y:
                x, y = y, x
            if randrange(4) == 0:
                print(x, y, 0, file = f)
            else:
                print(x, y, randrange(1, maxk), file = f)
