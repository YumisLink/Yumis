#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N=410,inf=200000000;
int a[N],f[N][N];

int main()
{
	freopen("wolf10.in","r",stdin);
	freopen("wolf10.out","w",stdout);
  int T=1;
  for (int cas=1;cas<=T;cas++)
    {
      int n,ans=0;cin>>n;
      for (int i=1;i<=n;i++)
	{
	  int x;cin>>x;ans+=x;
	}
      for (int i=1;i<=n;i++) cin>>a[i];
      a[0]=a[n+1]=0;
      for (int i=1;i<=n;i++)
	f[i][i]=a[i-1]+a[i+1];
      for (int j=1;j<n;j++)
	for (int i=1;j+i<=n;i++)
	  {
	    f[i][i+j]=inf;
	    for (int k=i;k<=i+j;k++)
	      {
		int now=a[i-1]+a[i+j+1];
		if (k>i) now+=f[i][k-1];
		if (k<i+j) now+=f[k+1][i+j];
		//cout<<i<<' '<<i+j<<' '<<k<<' '<<now<<endl;
		f[i][i+j]=min(f[i][i+j],now);
	      }
	  }
      cout<<ans+f[1][n]<<endl;
    }
  return 0;
}

