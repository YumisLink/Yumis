#include <cstdio>
#include <algorithm>
using namespace std;
struct R
{
    int t, id;
} r[100010];
bool god[100010];
bool cmp(const R a, const R b) { return a.id == b.id ? a.t < b.t : a.id < b.id; }
int n, d, k;
int main()
{
    scanf("%d%d%d", &n, &d, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &r[i].t, &r[i].id);
    sort(r + 1, r + n + 1, cmp);
    for (int i = 1; i <= n - k; i++)
    {
        if (r[i + k - 1].t - r[i].t <= d && r[i + k - 1].id == r[i].id)
            god[r[i].id] = 1;
    }
    for (int i = 1; i <= 100010; i++)
        if (god[i])
            printf("%d\n", i);
}