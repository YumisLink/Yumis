#include <algorithm>
#include <cstdio>
#define lovelive long long
lovelive fib[100], n, a, b;
void swap(lovelive &a, lovelive &b) {
  lovelive r = a;
  a = b;
  b = r;
}
void find(lovelive a, lovelive b) {
  if (b > a) swap(a, b);
  if (a == b) {
    printf("%lld\n", a);
    return;
  }
  int del = std::lower_bound(fib + 1, fib + 59, a) - fib;
  find(a - fib[del - 1], b);
}
int main() {
  fib[1] = 1;
  fib[2] = 2;
  for (int i = 3; fib[i - 1] < 1e12; i++) fib[i] = fib[i - 1] + fib[i - 2];
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a, &b);
    find(a, b);
  }
  
}