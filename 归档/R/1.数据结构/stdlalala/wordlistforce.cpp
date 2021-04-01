#include<bits/stdc++.h>
using namespace std;
const int N=510,L=1010,C=26;
int n,l[N]={},maxl1=0,maxl2=0;
long long sum1=0,sum2=0;
char ch[N][L]={},ans1[L]={},ans2[L]={},tmp[L]={};
int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.ans","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("\n%s",ch[i]);
		l[i]=strlen(ch[i]);
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			int p=0;
			while(p<l[i] && p<l[j] && ch[i][p]==ch[j][p])
				++p;
			if(p>maxl1 || (p==maxl1 && strncmp(ch[i],ans1,p)<0))
			{
				maxl1=p;
				copy(ch[i],ch[i]+p,ans1);
				sum1=0;
			}
			if(p==maxl1 && strncmp(ch[i],ans1,p)==0)
				++sum1;
			p=0;
			while(p<l[i] && p<l[j] && ch[i][l[i]-1-p]==ch[j][l[j]-1-p])
				++p;
			if(p>maxl2 || (p==maxl2 && strncmp(ch[i]+l[i]-p,ans2,p)<0))
			{
				maxl2=p;
				copy(ch[i]+l[i]-p,ch[i]+l[i],ans2);
				sum2=0;
			}
			if(p==maxl2 && strncmp(ch[i]+l[i]-p,ans2,p)==0)
				++sum2;
		}
	cout<<ans1<<' '<<sum1<<endl;
	cout<<ans2<<' '<<sum2<<endl;
}
