#include <cstdio>
int main()
{
    int qwe;
    scanf("%d", &qwe);
    for (int www = 1; www <= qwe; www++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r - l >= l)
            puts("NO");
        else
            puts("YES");
    }
}