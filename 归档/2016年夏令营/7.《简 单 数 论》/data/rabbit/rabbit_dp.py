idd = '0'

modulus = 10007
fi = open("rabbit" + idd + ".in")


def ft():
    l = fi.readline().split()
    return [int(x) for x in l]



fo = open("rabbit" + idd + ".ans", "w")

n, m = ft()
idx = [0] * (n + 1)
fib = [1, 1]
for i in range(100000):
    fib.append(fib[-1] + fib[-2])
for _ in range(m):
    l, r, k = ft()
    if k == 0:
        s = sum(fib[idx[x]] for x in range(l, r + 1))
        print(s % modulus, file = fo)
    else:
        for x in range(l, r+1):
            idx[x] += k

fi.close()
fo.close()