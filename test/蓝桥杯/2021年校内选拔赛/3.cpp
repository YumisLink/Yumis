#include <cstdio>
#define min(a, b) ((a) < (b) ? (a) : (b))
int n, m, c, k, dp[1 << 21], cot[110], dl;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &c);
    for (int j = 1; j <= c; j++) {
      scanf("%d", &k);
      printf("%d = %d\n", k, (1 << (k - 1)));
      cot[i] += (1 << (k - 1));
    }
  }
  dl = (1 << n) - 1;
  for (int i = 1; i <= dl; i++) dp[i] = 0x3f3f3f3f;
  dp[0] = 0;
  for (int i = 0; i <= dl; i++)
    for (int j = 1; j <= m; j++)
      dp[i | cot[j]] = min(dp[i | cot[j]], dp[i] + 1);
  printf("\n%d", dp[dl] < 0x3f3f3f3f ? dp[dl] : -1);
}