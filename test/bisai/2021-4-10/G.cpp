#include <cstdio>
int main() {
  int n;
  scanf("%d", &n);
  int q, w;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &q, &w);
    if (q == w)
      printf("%d\n", 2);
    else if (w == 1)
      printf("%d\n", q + 1);
    else
      puts("3");
  }
}