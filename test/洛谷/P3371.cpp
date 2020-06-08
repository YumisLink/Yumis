#include<cstdio>
#include<queue>
using namespace std;
queue<int>Q;
struct poi{int n,t,v;}p[500100];
int n,m,s,use[10010],inqueue[10010],range[10010];
void spfa(int x)
{
	Q.push(s); inqueue[s] = 1;range[s] = 0;
    while(!Q.empty())
    {
		int a = Q.front();Q.pop();inqueue[a] = 0;
		for (int i = use[a]; i; i = p[i].n)
        {
            if(range[a] + p[i].v < range[p[i].t]) 
            {
				range[p[i].t] = range[a] + p[i].v;
                Q.push(p[i].t);
                inqueue[p[i].t] = 1;
            }
        }
    }
}
int main ()
{
	scanf("%d%d%d",&n,&m,&s);
	for (int i = 1; i <= 10000;i ++) range[i] = 2147483647;
	for (int i = 1; i <= m; i ++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&p[i].t,&p[i].v);
		p[i].n = use[a]; use[a] = i;
	}
    spfa(s);
	for (int i = 1; i <= n; i++) printf("%d ",range[i]);
	return 0;
}