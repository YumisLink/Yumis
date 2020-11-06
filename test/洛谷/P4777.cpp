#include <cstdio>
#define MAXN 100010
#define lovelive long long
int qwe;
lovelive x, y;
lovelive a[100], b[100];
void ex_gcd(lovelive a, lovelive b, lovelive &x, lovelive &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    ex_gcd(b, a % b, x, y);
    int k = x;
    x = y;
    y = k - (a / b) * y;
}
int main()
{
    //scanf("%d", &qwe);
    qwe = 1;
    for (int www = 1; www <= qwe; www++)
    {
        lovelive n;
        lovelive ans = 0, mod = 1;
        // printf("%lld\n", ans);
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &a[i], &b[i]);
            mod *= a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            ex_gcd((mod / a[i]), a[i], x, y);
            ans += (b[i] * (x < 0 ? x + a[i] : x) * (mod / a[i]));
        }
        printf("%lld\n", ans % mod);
    }
}