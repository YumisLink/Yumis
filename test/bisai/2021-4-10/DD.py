import math
s = int(input())
for i in range(0,int(s)):
  k = input().split();
  l = int(1)
  r = int(1)
  l1 = int(k[0])
  l2 = int(k[2])
  r1 = int(k[1])
  r2 = int(k[3])
  cnt = 0
  i=l1
  j=l2
  lef = r1-l1
  rig = r2-l2
  kkk = math.max(lef,rig)
  if kkk > 10000:
    if l1 > l2 and r1 < r2:
      print("Yes")
      cnt = 1
    if l2 > r1 and l2 > l1:
      print("No")
      cnt = 1
    if l1 > r2 and l1 > l2:
      print("No")
      cnt = 1
  while i<=r1 or j<=r2:
    if cnt == 1:
        break
    if i<=r1:
      if i>=l2 and i<=r2:
        i=r2
      else:
        l *= i
    if j<=r2:
      if j>=l1 and j<=r1:
        j = r1
      else:
        r *= j
    qqq = math.gcd(l,r)
    l //= qqq
    r //= qqq
    i+=1
    j+=1
  if cnt != 1:
    if r % l == 0:
      print("Yes")
    else:
      print("No")