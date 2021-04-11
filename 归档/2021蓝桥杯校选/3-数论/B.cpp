#include <algorithm>
#include <cstdio>
long long fib[100], n, a, b;
int main() {
  fib[1] = 1, fib[2] = 2;
  for (int i = 3; fib[i - 1] < 1e15; i++) fib[i] = fib[i - 1] + fib[i - 2];
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a, &b);
    while (a != b) {
      if (a > b)
        a -= fib[std::lower_bound(fib + 1, fib + 63, a) - fib - 1];
      else
        b -= fib[std::lower_bound(fib + 1, fib + 63, a) - fib - 1];
    }
    printf("%lld\n", a);
  }
}