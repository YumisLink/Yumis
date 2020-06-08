#include<cstdio>
#include<queue>
using namespace std;
queue<int>Q;
int fr[200100],to[500010],sum[500010],ne[500010];
int head,dis[200100],n,m,q;
bool inque[200100];
void cin(int q, int w, int e){ne[head] = fr[q];fr[q] = head;to[head] = w;sum[head] = e;head++;}
void spfa(int x)
{
    Q.push(x);inque[x] = 1;dis[x] = 0;
    while(!Q.empty())
    {
        int k = Q.front();Q.pop();inque[k] = false;
        for (int i = fr[k]; i ;i = ne[i])
        {
            if (dis[to[i]] > dis[k] + sum[i])
            {
                dis[to[i]] = dis[k] + sum[i];
                Q.push(to[i]);
                inque[to[i]] = true;
            }
        }
    }
}
void xorbfs()
{
    Q.push(1);inque[1] = 1;dis[1] = 0;
    while(!Q.empty())
    {
        int k = Q.front();Q.pop();
        // printf("***%d ",k);
        for (int i = fr[k]; i ;i = ne[i])
        {
            if (!inque[to[i]])
            {
                dis[to[i]] = dis[k] ^ sum[i];
                inque[to[i]] = true;
                Q.push(to[i]);
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);head ++;
    for (int i = 1; i <= m; i ++)
    {
        int q,w,e;
        scanf("%d%d%d",&q,&w,&e);
        cin(q,w,e);cin(w,q,e);
    }
	//for (int i = 1; i <= 10000;i ++) dis[i] = 2147483647;
    xorbfs();
    for (int i = 1; i <= q; i++)
    {
        //memset(xo_r,0,sizeof(xo_r));
        int q,w;
        scanf("%d%d",&q,&w);
        printf("%d\n",dis[q]^dis[w]);
    }
	// for (int i = 1; i <= n; i++) printf("%d ",dis[i]);
    //printf("%d",0^5);
    // return 0;


    //memset(dis,INF,sizeof(dis));
    // puts("");

    // for (int i = 1; i <= n; i ++)
    //     for (int j = fr[i];j;j = ne[j])
    //     {
    //         printf("from %d  to  %d  sum  %d\n",i,to[j],sum[j]);
    //     }
    // }
}