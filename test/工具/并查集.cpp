#include<cstdio>
#define maxn 2000010 
using namespace std;
int n,m,s,u1,u2,st[maxn],re = 1,vis[maxn],fa[maxn],useo[maxn],ansum = 1,iid;
int ne[maxn],fr[maxn],to[maxn],fne[maxn],fin[maxn],fst[maxn],ans[maxn];
void hyman(int x,int y) {ne[re] = st[x]; st[x] = re; to[re] = y; re ++; return;}
void hy(int x,int y) {fne[re] = fst[x]; fst[x] = re; fin[re] = y; re ++; return;}
int find(int a) {return (fa[a] == a) ? a : fa[a] = find(fa[a]);}
void dfs(int x)
{
	vis[x] = 1;
	for (int k = st[x]; k; k = ne[k])
		if(!vis[to[k]])
			{dfs(to[k]); fa[to[k]] = x;}
	for (int k = fst[x]; k; k = fne[k])
		if(useo[fin[k]] && fin[k] != 0)
			ans[(k+1)/2] = find(fin[k]);
	useo[x] = 1;
}
int main ()
{
	scanf("%d%d%d",&n,&m,&s);
	for (int i = 1; i <= n-1; i++)
	{
		scanf("%d%d",&u1,&u2);fa[i] = i;
		hyman(u1,u2); hyman(u2,u1);
	}
	fa[n] = n; re = 1;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d",&u1,&u2);
		hy(u1,u2); hy(u2,u1);
	}
	dfs(s);
	for (int i = 1; i <= m; i++)
		printf("%d\n",ans[i]);
}