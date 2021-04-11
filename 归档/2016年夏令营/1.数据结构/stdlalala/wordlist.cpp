#include<bits/stdc++.h>
using namespace std;
const int L=500500,C=26;
int n;
int tot1=0,tr1[L][C]={},size1[L]={},maxl1=0;
int tot2=0,tr2[L][C]={},size2[L]={},maxl2=0;
long long sum1=0,sum2=0;
char ch[L]={},ans1[L]={},ans2[L]={},tmp[L]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("\n%s",ch+1);
		int l=strlen(ch+1);
		int p1=0,p2=0;
		for(int j=1;j<=l;++j)
		{
			if(tr1[p1][ch[j]-'a']==0)
				tr1[p1][ch[j]-'a']=++tot1;
			p1=tr1[p1][ch[j]-'a'];
			++size1[p1];
			if(size1[p1]>=2)
				maxl1=max(j,maxl1);
		}
		for(int j=l;j>=1;--j)
		{
			if(tr2[p2][ch[j]-'a']==0)
				tr2[p2][ch[j]-'a']=++tot2;
			p2=tr2[p2][ch[j]-'a'];
			++size2[p2];
			if(size2[p2]>=2)
				maxl2=max(l+1-j,maxl2);
		} 
	}
	//cout<<"maxl1="<<maxl1<<" maxl2="<<maxl2<<endl;
}
void dfs1(int p,int d)
{
	if(d==maxl1)
	{
		bool flag=false;
		for(int i=0;i<d;++i)
		{
			if(tmp[i]<ans1[i])
			{
				flag=true;
				break;
			}
			if(tmp[i]>ans1[i])
				break;
		}
		if(flag)
		{
			copy(tmp,tmp+d,ans1);
			sum1=size1[p]*1ll*(size1[p]-1)/2;
		}
		return;
	}
	for(int i=0;i<C;++i)
		if(tr1[p][i] && size1[tr1[p][i]]>=2)
		{
			tmp[d]='a'+i;
			dfs1(tr1[p][i],d+1);
			tmp[d]=0;
		}
}
void dfs2(int p,int d)
{
	if(d==maxl2)
	{
		bool flag=false;
		for(int i=d-1;i>=0;--i)
		{
			if(tmp[i]<ans2[i])
			{
				flag=true;
				break;
			}
			if(tmp[i]>ans2[i])
				break;
		}
		if(flag)
		{
			copy(tmp,tmp+d,ans2);
			sum2=size2[p]*1ll*(size2[p]-1)/2;
		}
		return;
	}
	for(int i=0;i<C;++i)
		if(tr2[p][i] && size2[tr2[p][i]]>=2)
		{
			tmp[d]='a'+i;
			dfs2(tr2[p][i],d+1);
			tmp[d]=0;
		}
}
void work()
{
	fill(ans1,ans1+maxl1,'z'+1);
	fill(ans2,ans2+maxl2,'z'+1);
	dfs1(0,0);
	printf("%s %I64d\n",ans1,sum1);
	dfs2(0,0);
	reverse(ans2,ans2+maxl2);
	printf("%s %I64d\n",ans2,sum2);
}
int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	init();
	work();
}
