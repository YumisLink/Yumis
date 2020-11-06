#include <cstdio>
#include <queue>
#define MAXN 100010
#define MAXM 1000100
using namespace std;
priority_queue<pair<int, int> > Q;
int st[MAXN], ne[MAXN], fr[MAXM], to[MAXM], dis[MAXM], snow[MAXN], tosnow[MAXN], ans[MAXN];
bool in[MAXN];
int n, m, s, t, g, q, head = 0;
void cin(int f, int t, int d)
{
    head++;
    ne[head] = st[f];
    st[f] = head;
    to[head] = t;
    dis[head] = d;
}
int main()
{
    scanf("%d%d%d%d%d%d", &n, &m, &s, &t, &g, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &snow[i], &tosnow[i]);
        ans[i] = 0x3f3f3f3f;
    }
    ans[s] = 0;
    for (int i = 1,q, w, e; i <= m; i++)
    {
        scanf("%d%d%d", &q, &w, &e);
        cin(q, w, e);
        cin(w, q, e);
    }
    Q.push(make_pair(0, s));
    while (!Q.empty())
    {
        int k = Q.top().second;
        Q.pop();
        if (ans[k] * q + snow[k] > tosnow[k])
            continue;
        for (int i = st[k]; i; i = ne[i])
        {
            if (ans[k] + dis[i] < ans[to[i]])
            {
                ans[to[i]] = ans[k] + dis[i];
                Q.push(make_pair(-ans[to[i]], to[i]));
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    //     for (int j = st[i]; j; j = ne[j])
    //         printf("fr %d to %d is %d\n", i, to[i], dis[i]);
    if (ans[t] == 0x3f3f3f3f || ans[t] > g)
        puts("wtnap wa kotori no oyatsu desu!");
    else
        printf("%d", ans[t]);
}

