#include <cstdio>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
char tree[1000];
char k[1000], head = 1;
int deep, num, cnt;
stack<int> S1, S2;
void create(int root, int dep)
{
    deep = max(deep, dep);
    tree[root] = k[head++];
    if (tree[root] != '#')
    {
        num++;
        create(root << 1, dep++);
        create(root << 1 | 1, dep++);
        if (tree[root << 1] == '#' && tree[root << 1 | 1] == '#')
            cnt++;
    }
}
void midfind(int root)
{
    if (root != 0 && tree[root] != '#')
    {
        midfind(root << 1);
        printf("%c ", tree[root]);
        midfind(root << 1 | 1);
    }
}
void frfind(int root)
{
    if (root != 0 && tree[root] != '#')
    {
        printf("%c ", tree[root]);
        midfind(root << 1);
        midfind(root << 1 | 1);
    }
}
void backfind(int root)
{
    if (root != 0 && tree[root] != '#')
    {
        midfind(root << 1);
        midfind(root << 1 | 1);
        printf("%c ", tree[root]);
    }
}
int main()
{
    scanf("%s", k + 1);create(1, 1);
    midfind(1);puts("");
    frfind(1);puts("");
    backfind(1);puts("");
    queue<int> Q;
    Q.push(1);
    while (!Q.empty())
    {
        int k = Q.front();
        printf("%c ", tree[k]);
        if (tree[k << 1] != '#')
        {
            Q.push(k << 1);
            S1.push(k);
        }
        if (tree[k << 1 | 1] != '#')
        {
            Q.push(k << 1 | 1);
            if (S1.top() == k)
            {
                S2.push(S1.top());
                S1.pop();
            }
            else
                S1.push(k);
        }
        Q.pop();
    }puts("");
    printf("%d", deep);puts("");
    printf("%d", num);puts("");
    printf("%d", cnt);puts("");
    printf("%d %d", S1.size(), S2.size());
}