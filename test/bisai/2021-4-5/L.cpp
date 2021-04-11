#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
long long n, a[MAXN];
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + n + 1);
  long long lef = 1, rig = n;
  long long lefa = a[1], riga = a[n];
  int ans = a[1];
  for (;;) {
    if (lefa < riga) {
      lefa += a[++lef];
      ans = a[lef] + 1;
    } else if (lefa > riga) {
      riga += a[--rig];
    }
    if (lefa == riga && a[lef + 1] != a[rig - 1]){
      lefa += a[++lef];
      riga += a[--rig];
    }
    if (lefa == riga && a[lef + 1] == a[rig - 1]) {
      ans = a[lef + 1];
      break;
    }
    if (lef >= rig) {
      break;
    }
  }
  cout << ans;
}