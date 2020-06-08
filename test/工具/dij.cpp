#include<cstdio>
#define MAXN 200100
#define INF 2147483647
int dui[MAXN],head,dhead,fr[MAXN],to[MAXN],way[MAXN],dis[MAXN],ne[MAXN],n,m,st,que[MAXN],close[MAXN],lig[MAXN],mlig[MAXN];
void cin(int f,int t,int d,int l){ne[++head] = fr[f];fr[f] = head;to[head] = t;way[head] = d;lig[head] = l;}
void swap(int &x,int &y){int t = x; x = y; y = t;}
void d_push(int k,int a)
{
    dui[++dhead] = k;que[dhead] = a;
    int p = dhead;
    while(p > 1)
        if (dui[p] < dui[p>>1])
            {swap(dui[p],dui[p>>1]);swap(que[p],que[p>>1]);p >>= 1;}
        else 
            break;
}
void d_pop()
{
    swap(dui[1],dui[dhead]);swap(que[1],que[dhead]);
    que[dhead] = dui[dhead] = 0;dhead--;int p = 1;
    while((p<<1) <= dhead)
    {
        int k = p<<1;if (k+1 <= dhead && dui[k] > dui[k+1]) k ++;
        if (dui[p] > dui[k]) {swap(dui[p],dui[k]);swap(que[p],que[k]);}
        else    break;
        p = k;
    }
}

int d_front(){return que[1];}
bool d_empty(){return dhead?0:1;}
void dij1(int r)
{
    d_push(0,r);
    dis[r] = 0;
    mlig[r] = 0;
    while(!d_empty())
    {
        int k = d_front();
        d_pop();
        if (close[k]) continue;
        close[k] = 1;
        for (int i = fr[k];i;i = ne[i])
        {
            if(dis[to[i]] > dis[k] + way[i])
            {
                dis[to[i]] = dis[k] + way[i];
                mlig[to[i]] = mlig[k] + lig[i];
                if (close[to[i]] == 0)
                    d_push(dis[to[i]],to[i]);

            }
        }
    }
}

void dij2(int r)
{
    d_push(0,r);
    mlig[r] = 0;
    dis[r] = 0;
    while(!d_empty())
    {
        int k = d_front();
        d_pop();
        if (close[k]) continue;
        close[k] = 1;
        for (int i = fr[k];i;i = ne[i])
        {
            if(mlig[to[i]] > mlig[k] + lig[i])
            {
                mlig[to[i]] = mlig[k] + lig[i];
                dis[to[i]] = dis[k] + way[i];
                if (close[to[i]] == 0)
                    d_push(mlig[to[i]],to[i]);

            }
        }
    }
}
void all()
{
    int ed = 0;char ch[100];
    scanf("%s\n",ch);
    int sun = 0;
    if (ch[0] == 'e') sun = 1;
    scanf("%d%d\n",&st,&ed);st++;ed++;
    for (int i = 1; i <= n+1; i ++) 
        dis[i] = INF,mlig[i] = INF;
    for (int i = 1; i <= m; i ++)
    {
        int q,w,e,r;
        scanf("%d%d%d%d",&q,&w,&e,&r);
        cin(q+1,w+1,r,e);
        // printf("%d**\n",sun);
    }
    if (sun) dij2(st);
    else dij1(st);
    printf("%d %d\n",mlig[ed],dis[ed]);
    for (int i = 1; i <= n+1 ; i ++)  fr[i] = 0;
    for (int i = 1; i <= m; i ++) ne[i] = 0,to[i] = 0,way[i] = 0,lig[i] = 0;;
}
int main ()
{
    while(scanf("%d%d\n",&n,&m) != EOF)
    {
        all();
    }
    
}