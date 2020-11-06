#include <cstdio>
#define MAXN 100010
#define sroot ch[0][0]
int ch[MAXN][2], fat[MAXN],  al[MAXN], he, n, m, lazy[MAXN];
char sum[MAXN];
void update(int root)
{
    if (root != 0)
        al[root] = al[ch[root][0]] + al[ch[root][1]] + 1;
}
int idt(int root) { return root == ch[fat[root]][0] ? 0 : 1; }

int find(int k)
{
    int root = ch[0][0];
    int rank = al[root] - al[ch[root][1]];
    while (k != rank)
    {
        if (k > rank)
        {
            root = ch[root][1];
            rank = rank + al[ch[root][0]] + 1;
        }
        else
        {
            root = ch[root][0];
            rank = rank - al[ch[root][1]] - 1;
        }
    }
    return root;
}
void connect(int son, int fa, int ple)
{
    fat[son] = fa;
    ch[fa][ple] = son;
}
void rotate(int root)
{
    int fa = fat[root];
    int gfa = fat[fa];
    int rfa = idt(root);
    int sonr = rfa ^ 1;
    int son = ch[root][sonr];
    int fagfa = idt(fa);
    if (son != 0)
        connect(son, fa, sonr ^ 1);
    else
        ch[fa][sonr ^ 1] = 0;
    connect(fa, root, sonr);
    connect(root, gfa, fagfa);
    update(fa);
    update(root);
}
void splay(int root, int to)
{
    for (; fat[root] != to;)
        rotate(root);
}
void midfind(int root)
{
    if (root == 0)
        return;
    midfind(ch[root][0]);
    if (root != n + 1 && root != n + 2 && sum[root] != '#')
        printf("%d ", sum[root]);
    midfind(ch[root][1]);
}
int create(int l, int r, int fa)
{
    if (l == 1 && r < l)
    {
        sum[n + 1] = '?';
        fat[n + 1] = fa;
        update(n + 1);
        return n + 1;
    }
    else if (r == n && l > r)
    {
        sum[n + 2] = '?';
        fat[n + 2] = fa;
        update(n + 2);
        return n + 2;
    }
    else if (l > r)
    {
        return 0;
    }
    printf("create %d %d\n",l,r);
    int mid = (l + r) >> 1;
    sum[mid] = getchar();
    fat[mid] = fa;
    ch[mid][0] = create(l, mid - 1, mid);
    ch[mid][1] = create(mid + 1, r, mid);
    update(mid);
    return mid;
}
int main()
{
    ch[0][0] = create(1, 12, 0);
    // for (int i = 1; i <= m; i++)
    // {
    //     int x, y;
    //     y += 2;
    //     int x1 = find(x), y1 = find(y);
    //     splay(x1, 0);
    //     splay(y1, x1);
    //     lazy[ch[y1][0]]++;
    // }
    midfind(sroot);
}