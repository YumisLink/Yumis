#include <algorithm>
#include <cmath>
#include <cstdio>
#include <utility>
#define MAXN 100010
int qwe;
int main() {
  scanf("%d", &qwe);
  for (int www = 1; www <= qwe; www++) {
    int n, k, a[100010];
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    std::sort(a + 1, a + 1 + n);
    bool c1 = false, c2 = true;
    if (a[1] == 0)
      for (int i = 2; i <= n; i++)
        if (a[i] != a[i - 1] + 1) c1 = true;
    if (!c1 && a[1] == 0) {
      printf("%d\n", n + k);
    } else {
      int me, ma = a[n];
      if (a[1] != 0)
        me = 0;
      else
        for (int i = 0; i <= n; i++)
          if (a[i] != a[i - 1] + 1) {
            me = a[i - 1] + 1;
            break;
          }
      int ad = round(((float)me + (float)ma) / 2);
      // printf("*********** ad = %d*\n",ad);
      for (int i = 1; i <= n; i++) {
        if (ad == a[i]) c2 = false;
      }
      if (c2)
        printf("%d\n", n + std::min(1,k));
      else
        printf("%d\n", n);
    }
  }
}