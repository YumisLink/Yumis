#include <cstdio>
#define ll long long
#define MAXN 100
ll n, a[MAXN], ans[MAXN];
int main()
{
    scanf("%lld", &n);
    int kkk = 0;
    for (int i = 1; i <= n; i++)
    {
        kkk = kkk ^ i;
        printf("%d : %d\n", i, kkk);
    }
}