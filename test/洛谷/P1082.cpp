#include <cstdio>
#define N 3000010
#define ll long long
ll inv[N], n, p;
int main()
{
    scanf("%lld%lld", n, p);
    inv[1] = 1;
    puts("1");
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (ll)(p - p / i) * inv[p % i] % p;
        printf("%lld\n", inv[i]);
    }
}