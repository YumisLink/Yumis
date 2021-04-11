query = [616042, 773582, 851346, 694379, 629948]

mq = max(query)
maxa = 2 * max(query) * max(query)
check = [0] * maxa
check[0] = 1
bp = 0
rec = 0
for i in range(maxa - max(query)):
    if check[i]:
        for j in query:
            check[i + j] = 1
        rec += 1
        if rec > mq:
            bp = i
            break
    else:
        rec = 0
ans0 = 0
ans1 = 0
for i in range(bp if bp else maxa):
    if not check[i]:
        ans0 += 1
        ans1 = i

print(ans0, ans1)