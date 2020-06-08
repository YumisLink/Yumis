#include<cstdio>
#define left (root<<1) 
#define mid ((l+r)/2)
#define right (root<<1|1)
#define father (root>>1)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define maxrange ((n<<1)-1)
#define ll long long
ll t[1<<19],lazy_add[1<<19],lazy_mti[1<<19],sum;
int fl,fr,n,m,p;
void update(int root)
{
    int tt = t[root],add = lazy_add[root];
    t[root] *= lazy_mti[root];
    lazy_add[root] *= lazy_mti[root];
    // lazy_add[father] += lazy_add[root] - add; t[father] += t[root] - tt;
    // printf("add %d t %lld  add[] %lld\n",father,lazy_add[root] - add,t[root] - tt);
    lazy_mti[left] *= lazy_mti[root]; lazy_mti[right] *= lazy_mti[root];
    lazy_mti[root] = 1;
}
void create(int root,int l,int r)
{
    lazy_mti[root] = 1;
    if (l == r){scanf("%lld",&t[root]);return;}
    create(root<<1,l,mid);create(root<<1|1,mid+1,r);
    t[root] = t[root<<1] + t[root<<1|1];
}
void add(int root,int l,int r)
{
    if (r < l || fl > r || fr < l || root > maxrange) return;
    update(root);
    if (fl <= l && r <= fr) lazy_add[root] += sum;
    else 
    {
        add(left,l,mid);
        add(right,mid+1,r);
        t[root] += sum * (min(r,fr) - max(l,fl) +1);
    }
}
ll mti(int root,int l,int r)
{
    if (r < l || fl > r || fr < l || root > maxrange) return 0;
    update(root);
    if (fl <= l && r <= fr) 
    {
        lazy_mti[root] *= sum;
        return (t[root] + lazy_add[root]) * lazy_mti[root];
    }
    else 
    {
        int k = mti(left,l,mid) + mti(right,mid+1,r);
        t[root] += k;
        return k;
    }
}
ll print(int root,int l,int r)
{
    if (r < l || fl > r || fr < l || root > maxrange) return 0;
    update(root);
    if (fl <= l && r <= fr)
        return t[root] + lazy_add[root] * (r-l+1);
    else 
    {
        if (root > maxrange) return 0;
        return (print(left,l,mid) + print(right,mid+1,r) + lazy_add[root] * (min(fr,r)-max(l,fl)+1));
    }
}

int main ()
{
    scanf("%d%d%d",&n,&m,&p);
    create(1,1,n);
    for(int i = 1; i <= m; i ++)
    {
        int zi;
        scanf("%lld",&zi);
        if (zi == 1){scanf("%d%d%d",&fl,&fr,&sum);mti(1,1,n);}
        if (zi == 2){scanf("%d%d%d",&fl,&fr,&sum);add(1,1,n);}
        if (zi == 3){scanf("%d%d",&fl,&fr);printf("%lld\n",print(1,1,n) % p);}
        fl = 1;fr = n;
        printf(" ***%lld\n",print(1,1,n));
        printf("just %lld  %lld  %lld  %lld  %lld\n",t[8],t[9],t[5],t[6],t[7]);
        for(int q = 1; q <= (n<<1|1) ;q ++)
            printf("%d:%lld ",q,t[q]);
        puts("");
        for(int q = 1; q <= (n<<1|1) ;q ++)
            printf("%d:%lld ",q,lazy_mti[q]);
        puts("");
        for(int q = 1; q <= (n<<1|1) ;q ++)
            printf("%d:%lld ",q,lazy_add[q]);
        puts("");
    }
}