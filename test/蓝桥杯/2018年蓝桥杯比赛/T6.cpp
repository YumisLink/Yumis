#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define INF 0x3f3f3f3f
using namespace std;
int a[MAXN], b[MAXN], c[MAXN], n;
int ans1[MAXN], ans2[MAXN], ans3[MAXN];
int main()
{
    scanf("%d", &n);
    a[n+1] = INF;b[n+1] = INF;c[n+1] = INF;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        ans1[i] = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
        ans2[i] = ans1[lower_bound(a + 1, a + n + 1, b[i]) - a - 1] + ans2[i-1];
    for (int i = 1; i <= n; i++)
        ans3[i] = ans2[lower_bound(b + 1, b + n + 1, c[i]) - b - 1] + ans3[i-1];
    printf("%d",ans3[n]);
    return 0;
}