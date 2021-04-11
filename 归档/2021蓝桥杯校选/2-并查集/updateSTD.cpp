#include <cstdio>
#define MAXN 300100
int n, m, tot, root[MAXN], size[MAXN];
int Find(int r) { return r != root[r] ? root[r] = Find(root[r]) : root[r]; }
int main() {
  scanf("%d%d", &n, &m);
  tot = n;
  for (int i = 1; i <= n; i++) root[i] = i, size[i] = 1;
  int t, u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &u, &v);
      int ru = Find(u), rv = Find(v);
      if (ru != rv) {
        tot--;
        root[ru] = rv;
        size[rv] += size[ru];
        size[ru] = 0;
      }
    }
    if (t == 2) {
      scanf("%d%d", &u, &v);
      puts(Find(u) == Find(v) ? "Yes" : "No");
    }
    if (t == 3) {
      scanf("%d", &u);
      printf("%d\n", size[Find(u)]);
    }
    if (t == 4) printf("%d\n", tot);
  }
}
