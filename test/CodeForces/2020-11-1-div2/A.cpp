#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100010
int a[MAXN], b[MAXN];
bool cmp(const int a, const int b) { return a > b; }
int main()
{
    int qwe;
    scanf("%d", &qwe);
    for (int www = 1; www <= qwe; www++)
    {
        int n, x;
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);

        bool flag = false;
        sort(b + 1, b + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] + b[i] > x)
                flag = true;
        }
        if (flag)
            puts("No");
        else
            puts("Yes");
    }
}