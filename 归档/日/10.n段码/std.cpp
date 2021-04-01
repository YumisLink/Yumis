#include <bits/stdc++.h>
using namespace std;
int a[7],par[7],res,e[7][7],m;
void init(int n)
{
	e[0][1]=e[0][5]=1;
	e[1][0]=e[1][2]=e[1][6]=1;
	e[2][1]=e[2][6]=e[2][3]=1;
	e[3][2]=e[3][4]=1;
	e[4][3]=e[4][5]=e[4][6]=1;
	e[5][4]=e[5][0]=e[5][6]=1;
	e[6][5]=e[6][4]=e[6][1]=e[6][2]=1;
	for(int i = 0;i < n;i++)
	{
		par[i] = i;
	}
}
int find(int x)
{
	if(par[x] == x) return x;
	return find(par[x]);	
}
void dfs(int idx)
{
	if(idx == m)
	{
		init(m);
		for(int i = 0;i < m;i++)
		{
			for(int j = 1;j < m;j++)
			{
				if(e[i][j]&&a[i]&&a[j])
				{
					int x = find(i);
					int y = find(j);
					if(x != y) par[x] = y;
				}
			}
		}
		int cnt = 0;
		for(int i = 0;i < m;i++)
		{
			if(par[i]==i && a[i])
			{
				cnt++;
			}
		}
		if(cnt==1){
			res++;
			for(int i = 0;i < m;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		return ;
	}
	a[idx] = 0;
	dfs(idx+1);
	a[idx] = 1;
	dfs(idx+1);
}

int main()
{
	cin>>m; 
	dfs(0);
	cout<<res<<endl;
	return 0;
}
