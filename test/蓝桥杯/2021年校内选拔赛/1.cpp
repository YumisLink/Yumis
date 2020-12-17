#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
int n, m, money[1010];
long long val[1010], dp[200000];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%lld", &money[i], &val[i]);
  for (int i = 1; i <= n; i++)
    for (int j = money[i]; j <= m; j++)
      dp[j] = max(dp[j - money[i]] + val[i], dp[j]);
  printf("%lld", dp[m]);
}