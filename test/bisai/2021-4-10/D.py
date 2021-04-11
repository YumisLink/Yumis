s = int(input())
for i in range(0,int(s)):
  k = input().split();
  l = 1
  r = 1
  tag = 0
  l1 = int(k[0])
  l2 = int(k[2])
  r1 = int(k[1])
  r2 = int(k[3])
  cnt = 0
  for j in range(l2,r2+1):
    if j >= l1 and j <= r1:
      j = r1
    else:   
      r *= j
      if r %  l1 and l1 <= r1 == 0:
        r /= l1
        l1 += 1
        cnt = 0
      else:
        cnt += 1
      if cnt == 10:
        cnt = 0
        l *= l1
        l1 +=1
  for j in range(l1,r1+1):
    if j >= l2 and j <= r2:
      j=r2
    else:   
      l *= j
  if r % l == 0:
    print("Yes")
  else:
    print("No")