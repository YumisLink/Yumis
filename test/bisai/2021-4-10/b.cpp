#include <cstdio>
#define MAXN 100010
int l, k;
int main() {
  scanf("%d%d", &l, &k);
  if (l == 2 && (k == 1 || k == 2 || k == 3))
    printf("Yes");
  else
    printf("No");
}