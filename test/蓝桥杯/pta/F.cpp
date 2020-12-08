#include <cstdio>
#define MAXN 100010
int n, a1, a2, p;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p);
        if (p % 2 == 0)
            a2++;
        else
            a1++;
    }
    printf("%d %d", a1, a2);
}