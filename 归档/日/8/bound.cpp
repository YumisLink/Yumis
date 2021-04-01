#include <cstdio>
#include <random>
int main() {
  freopen("0.in","w",stdout);
  int n = 10;
  srand(n);
  printf("%d\n",n);
  for (int i = 1; i <= n; i++) {
    int max = rand() % 6;
    for (int j = 1; j <= max + 1; j++) {
      char k = rand() % 26;
      if (rand() % 2 == 0)
        printf("%c", k + 'a');
      else
        printf("%c", k + 'A');
    }
    printf(" ");
  }
}