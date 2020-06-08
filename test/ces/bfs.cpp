#include<cstdio>
#define MAXN 200100
#define INF 2147483647
int dui[MAXN],head,dhead,fr[MAXN],to[MAXN],way[MAXN],dis[MAXN],ne[MAXN],n,m,st,que[MAXN],close[MAXN];
void cin(int f,int t,int d){ne[++head] = fr[f];fr[f] = head;to[head] = t;way[head] = d;}
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
    while(!d_empty())
    {
        int k = d_front();
        d_pop();
        if (close[k]) continue;
        close[k] = 1;
        for (int i = fr[k];i;i = ne[i])
        {
            // printf("Find %d to %d\n",k,to[i]);
            if(dis[to[i]] > dis[k] + way[i])
            {
                dis[to[i]] = dis[k] + way[i];
                if (close[to[i]] == 0)
                    d_push(dis[to[i]],to[i]);

            }
        }
    }
}
int main ()
{
    while(1)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0) return 0;
        head = 0;dhead = 0;
        for (int i = 1; i <= n+1; i ++) 
            dis[i] = INF;
        for (int i = 1; i <= m; i ++)
        {
            int q,w,e;
            scanf("%d%d%d",&q,&w,&e);
            cin(q,w,e);cin(w,q,e);
        }
        // for (int i = 1; i <= n ;i ++)
        //     for (int j = fr[i];j;j = ne[j])
        //         printf("F  %d  T %d  N %d\n",i,to[j],way[j]);
        dij1(1);
        printf("%d\n",dis[n]);
        for (int i = 1; i <= n+1 ; i ++)  fr[i] = 0;
        for (int i = 1; i <= m; i ++) ne[i] = 0,to[i] = 0,way[i] = 0,close[i] = 0;
    }
    
}