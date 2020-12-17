#include <bits/stdc++.h>
#define rd1(a, b) ((rand() * rand()) % (b - a + 1) + a)
using namespace std;

int rp[5010][5010], pt[5010][5010];
int add_x[10] = {0, -1, -1, -1, 0, 0, 0, 1, 1, 1};
int add_y[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int len, wit, cnt;
int main() {
  freopen("0.in", "w", stdout);
  int n = 500;
  int m = 100000;
  printf("500 100000\n");
  for (int i = 1; i <= n; i++)
    printf("%d %d\n", rd1(1, 50000), rd1(2, (int)1e9));
}