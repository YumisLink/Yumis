#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000010
bool x[20000010];
int main() {
  x[1] = true;
  for (int i = 3; i <= MAXN; i += 2)
    if (!x[i])
      for (int j = i; j <= MAXN; j += i) x[j] = true;
  int a;
  scanf("%d", &a);
  for (int qwe = 1; qwe <= a; qwe++) {
    int q, w, e, r;
    bool tag = true;
    scanf("%d%d%d%d", &q, &w, &e, &r);
    for (int i = q; i <= w; i++) {
      if (i >= e && i <= r)
        i = r;
      else if (!x[i])
        tag = false;
      if (!tag) break;
    }
    for (int i = e; i <= r; i++) {
      if (i >= q && i <= w)
        i = w;
      else if (!x[i])
        tag = false;
      if (!tag) break;
    }
    if (tag)
      puts("Yes");
    else
      puts("No");
  }
}