s = '''1000 2001 3000
10001 20000 30001
100001 200001 300000
1000000 2000000 3000001
10000000 20000000 30000001'''

i = 0
for l in s.splitlines():
    with open("apexis" + str(i) + ".in", "w") as f:
        print(l, file=f)
    i += 1
