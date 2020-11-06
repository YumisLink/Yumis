#include <cstdio>
#include <cmath>
#include <algorithm>
#define LoveLive long long
#define MAXN 1000100
int kk[MAXN], head;
bool zs[MAXN];
int qwe;
int main()
{
    kk[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        if (!zs[i])
        {
            for (int j = i; j <= 1000000; j += i)
            {
                if (!zs[j])
                {
                    head++;
                    kk[head] = j;
                    zs[j] = true;
                }
            }
        }
    }
    scanf("%d", &qwe);
    for (int www = 1; www <= qwe; www++)
    {
        LoveLive a, b;
        scanf("%lld%lld", a, b);
        LoveLive ans = a;
        for (int i = 2; i <= head; i++)
        {
            if (zs[i] > b)
                break;
            while (b % zs[i] == 0)
            {
                if (ans % zs[i] == 0)
                    ans / zs[i];
                b /= zs[i];
            }
        }
        printf("%lld\n", ans);
    }
}