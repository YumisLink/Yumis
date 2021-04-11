#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
long long f[89],a[89],n,g[89][2];   
int m=0,t;
int main()
{
  freopen("fibonacci10.in","r",stdin);
  freopen("fibonacci10.out","w",stdout);
  scanf("%d",&t);
  f[1]=1; f[2]=2;
  for(int i=3;i<=88;i++)   f[i]=f[i-1]+f[i-2];
  while (t--)
    {
      cin >> n;
      m=0;
      for(int i=88;i>=1;i--)
	if(f[i]<=n)
	  n-=f[i],a[++m]=1LL*i;
      reverse(a+1,a+m+1);
      g[1][1]=1;
      g[1][0]=(a[1]-1)>>1;
      for(int i=2;i<=m;i++)
	{
	  g[i][1] = g[i-1][0]+g[i-1][1];
	  g[i][0]= ((a[i] - a[i-1] - 1) >> 1) * g[i-1][1] + ((a[i]-a[i-1])>>1) * g[i-1][0];
        }
      cout << g[m][0] + g[m][1] << endl;
    }
}
