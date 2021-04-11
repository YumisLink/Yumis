#include <cstdio>
int check1(int y) {
  if (y % 400 == 0) return 2;
  if (y % 100 == 0) return 0;
  if (y % 4 == 0) return 1;
  return 0;
}
int main() {
  int n, k;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k);
    if (check1(k == 2))
      printf("%d is shiji runnian!\n");
    if (check1(k == 1))
      printf("%d is putong runnian!\n");
    if (check1(k == 0))
      printf("%d not is runnian!\n");
  }
}
