#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
const int maxn=70000,maxm=2000000,inf=1000000;
int n,m,source,sink,p[50],check[203],tot=0,id[203][203],tote=0,Link[maxn],h[maxn],s[maxn];
struct Tedge
{
    int t,v,op,pre;
    Tedge(){}
    Tedge(int _t,int _v,int _op,int _pre){t=_t,v=_v,op=_op,pre=_pre;}
}g[maxm];

int init()
{
    n=get(),m=get();
    for(int i=2;i<=200;i++)
    {
        if(check[i])continue;else p[++tot]=i;
        for(int j=i+i;j<=200;j+=i)check[j]=1;
    }
    for(int i=1,cnt=0;i<=tot;i++)
        for(int j=1;j<=tot;j++)id[i][j]=++cnt;
}

inline void add(int s,int t,int v)
{
    int tp;
    tp=Link[s]; Link[s]=++tote; g[tote]=Tedge(t,v,tote+1,tp);
    tp=Link[t]; Link[t]=++tote; g[tote]=Tedge(s,0,tote-1,tp);
}

void build()
{
    source=n+m+tot*tot*3+1,sink=source+1;
    int Tx,Ty,Tz,fx[10],fy[10],fz[10],inf=n+m;
    for(int i=1;i<=n;i++)add(source,i,1);
    for(int i=1;i<=m;i++)add(i+n,sink,1);
    for(int i=1;i<=n;i++)
    {
        int x=get(),y=get(),z=get();
        Tx=0,Ty=0,Tz=0;
        for(int j=1;j<=tot;j++)
        {
            if(x%p[j]==0)fx[++Tx]=j;
            if(y%p[j]==0)fy[++Ty]=j;
            if(z%p[j]==0)fz[++Tz]=j;
        }
        for(int j=1;j<=Tx;j++)
            for(int k=1;k<=Ty;k++)
                add(i,n+m+id[fx[j]][fy[k]],inf);
        for(int j=1;j<=Tx;j++)
            for(int k=1;k<=Tz;k++)
                add(i,n+m+tot*tot+id[fx[j]][fz[k]],inf);
        for(int j=1;j<=Ty;j++)
            for(int k=1;k<=Tz;k++)
                add(i,n+m+tot*tot*2+id[fy[j]][fz[k]],inf);
    }
    for(int i=1;i<=m;i++)
    {
        int x=get(),y=get(),z=get();
        Tx=0,Ty=0,Tz=0;
        for(int j=1;j<=tot;j++)
        {
            if(x%p[j]==0)fx[++Tx]=j;
            if(y%p[j]==0)fy[++Ty]=j;
            if(z%p[j]==0)fz[++Tz]=j;
        }
        for(int j=1;j<=Tx;j++)
            for(int k=1;k<=Ty;k++)
                add(n+m+id[fx[j]][fy[k]],i+n,inf);
        for(int j=1;j<=Tx;j++)
            for(int k=1;k<=Tz;k++)
                add(n+m+tot*tot+id[fx[j]][fz[k]],i+n,inf);
        for(int j=1;j<=Ty;j++)
            for(int k=1;k<=Tz;k++)
                add(n+m+tot*tot*2+id[fy[j]][fz[k]],i+n,inf);
    }
}

inline bool bfs()
{
    int front=0,rear=1;
    for(int i=1;i<=sink;i++)h[i]=-1;
    h[source]=1,s[front]=source;
    while(front!=rear)
    {
        int p=s[front];
        for(int i=Link[p];i;i=g[i].pre)
            if(h[g[i].t]==-1&&g[i].v)h[g[i].t]=h[p]+1,s[rear++]=g[i].t;
        front++;
    }
    return h[sink]!=-1;
}

int aug(int x,int flow)
{
    if(x==sink)return flow;
    int tp=flow,d;
    for(int i=Link[x];i;i=g[i].pre)
    {
        if(h[g[i].t]!=h[x]+1||g[i].v<=0)continue;
        d=min(g[i].v,tp),d=aug(g[i].t,d);
        g[i].v-=d,g[g[i].op].v+=d;tp-=d;
        if(tp==0)break;
    }
    if(tp==flow)h[x]=-1;
    return flow-tp;
}

void work()
{
    int ans=0;
    while(bfs())ans+=aug(source,inf);
    printf("%d\n",ans);
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    init();
    build();
    work();
    return 0;
}
