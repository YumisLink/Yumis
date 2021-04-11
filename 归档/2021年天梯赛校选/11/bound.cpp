#include <cstdio>
#include <random>
#include <time.h>
int main() {
  freopen("0.in", "w", stdout);
  int n = 1;
  srand(time(0));
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) {
    int k = rand() % 20 + 10;
    printf("%d\n",k);
    for (int j = 1; j <= k; j++) {
      printf("%d ", rand() % 100000+1);
    }
    puts("");
  }
}