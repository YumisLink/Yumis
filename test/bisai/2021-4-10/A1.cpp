#include <bits/stdc++.h>
#define MAXN 105
#define lovelive long long
lovelive k, n, MOD = 1000000007;
struct matrix {
  lovelive mx[MAXN][MAXN];
  matrix() { std::memset(mx, 0, sizeof(mx)); }
  void build() {
    for (lovelive i = 1; i <= n; i++) mx[i][i] = 1;
  }
  void print() {
    for (lovelive i = 1; i <= n; puts(""), i++)
      for (lovelive j = 1; j <= n; j++) printf("%lld ", mx[i][j]);
  }
} init, base;
matrix operator*(matrix A, matrix B) {
  matrix ret;
  for (lovelive i = 1; i <= n; i++)
    for (lovelive j = 1; j <= n; j++)
      for (lovelive k = 1; k <= n; k++)
        ret.mx[i][j] = (ret.mx[i][j] + (B.mx[i][k] * A.mx[k][j]) % MOD) % MOD;
  return ret;
}

int main() {
  int rn, rk,k;
  scanf("%d",&k);
  for (int qwe = 1; qwe <= k; qwe++) {
    // scanf("%lld%lld", &n);
    n = 2;
    // scanf("%lld%lld", &rn);
    // base.build();
    for (lovelive i = 1; i <= n; i++)
      for (lovelive j = 1; j <= n; j++) scanf("%lld", &init.mx[i][j]);
    for (lovelive i = 1; i <= n; i++)
      for (lovelive j = 1; j <= n; j++) scanf("%lld", &base.mx[i][j]);
    // while (k) {
    //   if (k & 1) base = base * init;
    //   init = init * init;
    //   k >>= 1;
    // }
    base = base * init;
    base.print();
  }
}