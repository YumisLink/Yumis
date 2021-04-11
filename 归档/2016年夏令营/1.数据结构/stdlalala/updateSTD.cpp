#include <bits/stdc++.h>
using namespace std;
const int N = 100050, M = 200100;
int n, m, num[N] = {}, now = 0, tot = 0, root[N + M] = {}, size[N + M] = {};
int Find(int r) {
  if (r != root[r]) root[r] = Find(root[r]);
  return root[r];
}
int main() {
  scanf("%d%d", &n, &m);
  now = tot = n;
  for (int i = 1; i <= n; ++i) num[i] = root[i] = i, size[i] = 1;
  int t, u, v;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &u, &v);
      int ru = Find(num[u]), rv = Find(num[v]);
      if (ru != rv) {
        --tot;
        root[ru] = rv;
        size[rv] += size[ru];
        size[ru] = 0;
      }
    }
    if (t == 2) {
      scanf("%d%d", &u, &v);
      puts(Find(num[u]) == Find(num[v]) ? "Yes" : "No");
    }
    if (t == 3) {
      scanf("%d", &u);
      printf("%d\n", size[Find(num[u])]);
    }
    if (t == 4) printf("%d\n", tot);
  }
}
