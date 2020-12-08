#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 200100
using namespace std;
queue<int> Q;
vector<int> V[MAXN];
int n, m;
int in[MAXN];
void cin(int a, int b)
{
    V[a].push_back(b);
    in[b]++;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int q, w;
        scanf("%d%d", &q, &w);
        cin(q, w);
    }
    for (int i = 1; i <= n; i++)
        if (!in[i])
            Q.push(i);
    while (!Q.empty())
    {
        int k = Q.front();
        printf("%d ", k);
        Q.pop();
        for (int i = 0; i < V[k].size(); i++)
        {
            in[V[k][i]]--;
            if (!in[V[k][i]])
                Q.push(V[k][i]);
        }
    }
}