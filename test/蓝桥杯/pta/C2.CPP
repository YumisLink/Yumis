#include <cstdio>
#include <queue>
using namespace std;
int n, a[100], rr[100], ll[100];
int s1[100], s2[100], head;
queue<int> Q, pt;
int finds1(int f)
{
    for (int i = 1; i <= n; i++)
        if (s1[i] == f)
            return i;
    return -1;
}
int dfs(int l, int r, int top)
{
    if (l > r)
        return 0;
    int t = top;
    int mid = finds1(s2[t]);
    a[++head] = s2[t];
    int rt = head;
    rr[rt] = dfs(l, mid - 1, top + 1);
    ll[rt] = dfs(mid + 1, r, top + (mid - l + 1));
    return rt;
}
void swap(int root)
{
    int k = rr[root];
    rr[root] = ll[root];
    ll[root] = k;
}
void midswap(int root)
{
    if (root == 0)
        return;
    swap(root);
    midswap(rr[root]);
    midswap(ll[root]);
}
void midf(int root)
{
    if (root == 0)
        return;
    midf(rr[root]);
    printf("%d ", a[root]);
    midf(ll[root]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &s1[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &s2[i]);
    dfs(1, n, 1);
    midswap(1);
    Q.push(1);
    while (!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        if (k == 0)
            continue;
        pt.push(k);
        Q.push(rr[k]);
        Q.push(ll[k]);
    }
    while (!pt.empty())
    {
        int k = pt.front();
        pt.pop();
        if (pt.empty())
            printf("%d", a[k]);
        else
            printf("%d ", a[k]);
    }
}