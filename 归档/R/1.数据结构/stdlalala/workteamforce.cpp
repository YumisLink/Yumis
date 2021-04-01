#include<bits/stdc++.h>
using namespace std;
const int N=50050,M=100100;
int n,m,root[N]={};
int main()
{
	freopen("workteam.in","r",stdin);
	freopen("workteam.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		root[i]=i;
	int t,u,v;
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&u,&v);
			int ru=root[u],rv=root[v];
			for(int i=1;i<=n;++i)
				if(root[i]==ru)
					root[i]=rv;
		}
		if(t==2)
		{
			scanf("%d",&u);
			if(root[u]!=u)
				root[u]=u;
			else
			{
				int nr=0;
				for(int i=1;i<=n;++i)
					if(i!=u && root[i]==u)
						nr=i;
				for(int i=1;i<=n;++i)
					if(i!=u && root[i]==u)
						root[i]=nr;
			}
		}
		if(t==3)
		{
			scanf("%d%d",&u,&v);
			puts(root[u]==root[v] ? "Yes" : "No");
		}
		if(t==4)
		{
			scanf("%d",&u);
			int tot=0;
			for(int i=1;i<=n;++i)
				if(root[i]==root[u])
					++tot;
			printf("%d\n",tot);
		}
		if(t==5)
		{
			int totg=0;
			for(int i=1;i<=n;++i)
				if(root[i]==i)
					++totg;
			printf("%d\n",totg);
		}
	}
}
