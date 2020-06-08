#include<cstdio>
#include<map>
#define MAXN 100010
#define LL long long
using namespace std;
map<LL ,LL>M;
LL fa[MAXN],ne[MAXN],head,t[MAXN],n,now,at,fr,a,b,c,name[MAXN];
void del(LL ti)
{
    now = b;
    if (t[fr] == 0) return;
    while(ti)
    {
        if (t[fr] == 0) break;
        if (t[fr] <= ti)
        {
            for(int i = fr;i;i = ne[i])
                printf("%d ",t[i]);
            puts("");
            LL root = fr;
            ti -= t[root];
            fr = ne[root];
            printf("%lld\n",name[root]);
            name[root] = t[root] = ne[root] = 0;
            fa[fr] = 0;
        }
        else 
        {
            t[fr] -= ti;
            return ;
        }
    }
}
void upper(LL root)  //将链表中的root提升到头
{
    ne[fa[root]] = ne[root];
    fa[ne[root]] = fa[root];
    fa[root] = 0;
    ne[root] = fr;
    fr = root;
}

int main ()
{
    // freopen("Yumis1.in","r",stdin);
    // freopen("a","w",stdout);
    scanf("%lld%lld",&n,&at);
    now = 0;
    for (int i = 1 ; i <= n; i ++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if (a == 1)
        {
            del(b-now);
            LL time;
            scanf("%lld",&time);
            head ++;
            t[head] = time;
            M[c] = head;
            fa[fr] = head;
            ne[head] = fr;
            fr = head;
            name[head] = c;
            
        }
        if (a == 2)
        {
            del(b-now);
            upper(M[c]);
        }
    }
    del(at-now);
}