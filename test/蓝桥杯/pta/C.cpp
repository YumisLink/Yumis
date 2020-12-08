#include <cstdio>
#define MAXN 100010
int n, A, B, a, b;
int main()
{
    scanf("%d%d%d", &a, &b, &n);
    for (int q, w, e, r, i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &q, &w, &e, &r);
        int al = q + e;
        if (w == al)
            A++;
        if (r == al)
            B++;
        if (w == al && r == al)
            A--, B--;
        if (A > a)
        {
            printf("A\n%d", B);
            return 0;
        }
        if (B > b)
        {
            printf("B\n%d", A);
            return 0;
        }
    }
}