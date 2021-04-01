id = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

ns = [6, 6, 100, 100, 100, 100, 100000, 100000, 100000, 100000]
df = [1, 1, 1, 50, 50, 50, 4000, 4000, 4000, 10000]
T = 10

from random import randrange

ll = len(id)

for i in range(ll):
    with open("quest" + id[i] + '.in', "w") as f:
        print(T, file=f)
        for di in range(T):
            if ns[i] == 100000:
                dfactor = df[di]
            else:
                dfactor = 1
            print(ns[i], randrange(2, int((ns[i] * dfactor) ** 0.4)+ 1), file=f)
            s = ""
            for x in range(ns[i] // dfactor):
                s += str(randrange(2, ns[i])) + " "
            s = s * dfactor
            for __ in range(ns[i] % dfactor):
                s += str(randrange(2, ns[i])) + " "
            print(s, file=f)
