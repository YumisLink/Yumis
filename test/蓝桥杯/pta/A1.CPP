#include <cstdio>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<pair<int, pair<int, int> > > Q;
int k[10010], qhb[10010], n, a, b, del;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int l;
        scanf("%d", &l);
        map<int, int> M;
        del = 0;
        for (int j = 1; j <= l; j++)
        {
            scanf("%d%d", &a, &b);
            if (!M[a])
            {
                k[a] += b;
                M[a] = 1;
                del += b;
                qhb[a]++;
            }
        }
        k[i] -= del;
    }
    for (int i = 1; i <= n; i++)
        Q.push(make_pair(k[i], make_pair(qhb[i], -i)));
    while (!Q.empty())
    {
        int k = Q.top().first;
        printf("%d %d.%d\n", -Q.top().second.second, k / 100, abs(k) % 100);
        Q.pop();
    }
}