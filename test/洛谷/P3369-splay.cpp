#include<cstdio>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define sroot ch[0][0]
int ch[MAXN][2],fat[MAXN],sum[MAXN],al[MAXN],he,n,m,lazy[MAXN];
void update(int root){if (root != 0) al[root] = al[ch[root][0]]+al[ch[root][1]] +1;}
void swap(int root){int left = ch[root][0];ch[root][0] = ch[root][1];ch[root][1] = left;update(root);}
int idt(int root) {return root==ch[fat[root]][0]?0:1;}
void pulldown(int root) 
{
    int k = lazy[root]%2==0?0:1;
    lazy[root] = 0;
    lazy[ch[root][0]] += k;
    lazy[ch[root][1]] += k;y
}
int create(int l,int r,int fa)
{
    if (l == 1 && r < l){sum[n+1] = -INF;fat[n+1] = fa;update(n+1);return n+1;}
    else if (r == n && l > r) {sum[n+2] = INF;fat[n+2] = fa;update(n+2);return n+2;}
    else if (l > r) { return 0; }
    int mid = (l+r)>>1;
    sum[mid] = mid;
    fat[mid] = fa;
    ch[mid][0] = create(l,mid-1,mid);
    ch[mid][1] = create(mid+1,r,mid);
    update(mid);
    return mid;
}
int find(int k)
{
    int root = ch[0][0];
    int rank = al[root]-al[ch[root][1]];
    while (k != rank)
    {
        if (lazy[root]%2 != 0){pulldown(root);swap(root);}
        if (k > rank)
        {
            root = ch[root][1];
            if (lazy[root]%2 != 0){pulldown(root);swap(root);}
            rank = rank + al[ch[root][0]] + 1;
        }
        else 
        {
            root = ch[root][0];
            if (lazy[root]%2 != 0){pulldown(root);swap(root);}
            rank = rank - al[ch[root][1]] - 1;
        }
    }
    return root;
}
void connect(int son,int fa,int ple){fat[son] = fa;ch[fa][ple] = son;}
void rotate(int root)
{
    int fa = fat[root];
    int gfa = fat[fa];
    int rfa = idt(root);
    int sonr = rfa^1;
    int son = ch[root][sonr];
    int fagfa = idt(fa);
    connect(son,fa,sonr^1);
    connect(fa,root,sonr);
    connect(root,gfa,fagfa);
    update(fa);update(root);
}
void splay(int argument0)
{
    int root = argument0;
    while(fat[root] != 0)
        rotate(root);
}
void midfind(int root)
{
    if (root == 0 ) return;
    if (lazy[root]%2 != 0){pulldown(root);swap(root);}
    midfind(ch[root][0]);
    if (root != n+1 && root != n+2) printf("%d ",sum[root]);
    midfind(ch[root][1]);
}
int main ()
{
    scanf("%d%d",&n,&m);
    ch[0][0] = create(1,n,0);
    for(int i = 1; i <= m; i ++)
    {
        int x,y;
        scanf("%d%d",&x,&y);y+=2;
        int x1 = find(x),y1=find(y);
        splay(y1);
        splay(x1);
        lazy[ch[y1][0]] ++;
    }
        midfind(sroot);
}